#include "GameController.h"
#include <SDL.h>

GameController::GameController() : mouseMovedAction(nullptr)
{

}


InputAction GameController::GetActionForKey(InputKey key)
{
    for(const auto& btnAction : buttonActions)
    {
        if(key == btnAction.key)
        {
            return btnAction.action;
        }
    }

    return [](uint32_t, InputState){};
}

void GameController::AddInputActionForKey(const ButtonAction& buttonAction)
{
    buttonActions.push_back(buttonAction);
}

void GameController::clearAll()
{
    buttonActions.clear();
}

bool GameController::isPressed(InputState state)
{
    return SDL_PRESSED;
}

bool GameController::isReleased(InputState state)
{
    return SDL_RELEASED;
}

InputKey GameController::actionKey()
{
    return static_cast<InputKey>(SDLK_a);
}

InputKey GameController::cancelKey()
{
    return static_cast<InputKey>(SDLK_s);
}

InputKey GameController::leftKey()
{
    return static_cast<InputKey>(SDLK_LEFT);
}

InputKey GameController::rightKey()
{
    return static_cast<InputKey>(SDLK_RIGHT);
}

InputKey GameController::upKey()
{
    return static_cast<InputKey>(SDLK_UP);
}

InputKey GameController::downKey()
{
    return static_cast<InputKey>(SDLK_DOWN);
}

MouseInputAction GameController::getMouseButtonActionForMouseButton(MouseButton btn)
{
    for(const auto& buttonAction : mouseButtonActions)
    {
        if(btn == buttonAction.mouseButton)
        {
            return buttonAction.mouseInputAction;
        }
    }

    return [](InputState state, const MousePosition& pos){};
}

void GameController::AddMouseButtonAction(const MouseButtonAction& msButtonAction)
{
    mouseButtonActions.push_back(msButtonAction);
}

MouseButton GameController::LeftMouseButton()
{
    return static_cast<MouseButton>(SDL_BUTTON_LEFT);
}

MouseButton GameController::RightMouseButton()
{
    return static_cast<MouseButton>(SDL_BUTTON_RIGHT);
}
