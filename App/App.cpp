#include <iostream>
#include "App.h"
#include "SDL.h"
#include "../Scenes/ArcadeScene.h"
#include <cassert>

App& App::Singleton()
{
    static App theApp;
    return theApp;
}


bool App::Init(uint32_t width, uint32_t height, uint32_t magnify)
{
    window = screen.Init(width, height, magnify);

    std::unique_ptr<ArcadeScene> arcadeScene = std::make_unique<ArcadeScene>();

    PushScene(std::move(arcadeScene));

    return window != nullptr;
}


void App::Run()
{
    if(window)
    {
        bool running = true;

        uint32_t lastTick = SDL_GetTicks();
        uint32_t currentTick = lastTick;

        uint32_t dt = 10;
        uint32_t accumulator = 0;

        inputController.Init( [&running](uint32_t dt, InputState state)
        {
            running = false;
        });

        while(running)
        {
            currentTick = SDL_GetTicks();
            uint32_t frameTime = currentTick - lastTick;

            if(frameTime > 300)
            {
                frameTime = 300;
            }

            lastTick = currentTick;

            accumulator += frameTime;

            // Input
            inputController.Update(dt);

            Scene* topScene = App::TopScene();

            assert(topScene && "Scene missing");
            if(topScene)
            {
                // Update
                while(accumulator >= dt)
                {
                    // update current scene by dt
                    topScene->Update(dt);
                    //std::cout << "Delta time step: " << dt << std::endl;
                    accumulator -= dt;
                }

                // Render
                topScene->Draw(screen);
            }

            screen.swapScreen();
        }
    }
}

void App::PushScene(std::unique_ptr<Scene> scene)
{
    assert(scene && "Don't push nullptr");
    if(scene)
    {
        scene->Init();
        inputController.SetGameController(scene->getGameController());

        SceneStack.emplace_back(std::move(scene));
        SDL_SetWindowTitle(window, TopScene()->GetSceneName().c_str());
    }
}

void App::PopScene()
{
    if(SceneStack.size() > 1)
    {
        SceneStack.pop_back();
    }

    if(TopScene())
    {
        inputController.SetGameController(TopScene()->getGameController());

        SDL_SetWindowTitle(window, TopScene()->GetSceneName().c_str());
    }
}

Scene* App::TopScene()
{
    if(SceneStack.empty())
    {
        return nullptr;
    }

    return SceneStack.back().get();
}
