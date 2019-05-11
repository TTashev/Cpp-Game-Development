#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "InputAction.h"
#include <vector>

class GameController
{
public:
    GameController();
    InputAction GetActionForKey(InputKey key);
    void AddInputActionForKey(const ButtonAction& buttonAction);
    void clearAll();

    static bool isPressed(InputState state);
    static bool isReleased(InputState state);
    static InputKey actionKey();
    static InputKey cancelKey();
    static InputKey leftKey();
    static InputKey rightKey();
    static InputKey upKey();
    static InputKey downKey();

    inline const MouseMovedAction& getMouseMovedAction() {return mouseMovedAction;}
    inline void setMouseMovedAction(const MouseMovedAction& msMovedAction) {mouseMovedAction = msMovedAction;}

    MouseInputAction getMouseButtonActionForMouseButton(MouseButton btn);
    void AddMouseButtonAction(const MouseButtonAction& msButtonAction);

    static MouseButton LeftMouseButton();
    static MouseButton RightMouseButton();

private:
    std::vector<ButtonAction> buttonActions;
    std::vector<MouseButtonAction> mouseButtonActions;
    MouseMovedAction mouseMovedAction;
};

#endif // GAMECONTROLLER_H
