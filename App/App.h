#ifndef APP_H
#define APP_H

#include "../include/Screen.h"
#include "../Scenes/Scene.h"
#include "../Input/InputController.h"
#include <stdint.h>
#include <memory>
#include <vector>

struct SDL_Window;

class App
{
public:
    static App& Singleton();
    bool Init(uint32_t width, uint32_t height, uint32_t magnify);
    void Run();

    inline uint32_t Width() const {return screen.Width();}
    inline uint32_t Height() const {return screen.Height();}

    void PushScene(std::unique_ptr<Scene> scene);
    void PopScene();
    Scene* TopScene(); // current scene

private:
    Screen screen;
    SDL_Window * window;

    std::vector<std::unique_ptr<Scene>> SceneStack;
    InputController inputController;
};

#endif // APP_H
