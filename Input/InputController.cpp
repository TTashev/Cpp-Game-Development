#include "InputController.h"
#include "GameController.h"
#include <SDL.h>

InputController::InputController() : quit(nullptr), currentController(nullptr)
{

}

void InputController::Init(InputAction quitAction)
{
    quit = quitAction;
}

void InputController::Update(uint32_t dt)
{
    SDL_Event sdlEvent;

    while( SDL_PollEvent(&sdlEvent) )
    {
        switch(sdlEvent.type)
        {
            case SDL_QUIT:
            {
                this->quit(dt, SDL_PRESSED);
            }
            case SDL_MOUSEMOTION:
            {
                if(this->currentController)
                {
                    if(MouseMovedAction mouseMoved = this->currentController->getMouseMovedAction())
                    {
                        MousePosition pos;
                        pos.xPos = sdlEvent.motion.x;
                        pos.yPos = sdlEvent.motion.y;
                        mouseMoved(pos);
                    }
                }
                break;
            }
            case SDL_MOUSEBUTTONUP:
            case SDL_MOUSEBUTTONDOWN:
                if(this->currentController)
                {
                    MouseInputAction action = this->currentController->getMouseButtonActionForMouseButton(static_cast<MouseButton>(sdlEvent.button.button));

                    MousePosition pos;
                    pos.xPos = sdlEvent.button.x;
                    pos.yPos = sdlEvent.button.y;

                    action(static_cast<InputState>(sdlEvent.button.state), pos);
                }
                break;

            case SDL_KEYDOWN:
            case SDL_KEYUP:

                if(this->currentController)
                {
                    InputAction action = this->currentController->GetActionForKey(sdlEvent.key.keysym.sym);

                    action(dt, static_cast<InputState>(sdlEvent.key.state));
                }
                break;
        }
    }
}

void InputController::SetGameController(GameController * controller)
{
    this->currentController = controller;
}
