#include <math.h>
#include <iostream>

#include "../Input/GameController.h"
#include "ArcadeScene.h"
#include "../../Section-6-Full-Source/Utils/Utils.h"
#include "../include/Screen.h"
#include "../Graphics/Triangle.h"
#include "../Graphics/AARectangle.h"
#include "../Graphics/Circle.h"
#include "../Graphics/Star2D.h"
#include "../Graphics/Line2D.h"
#include "../Graphics/Color.h"

static const int SCREEN_WIDTH = 224;
static const int SCREEN_HEIGHT = 288;
static const int MAGNIFICATION = 3;


ArcadeScene::ArcadeScene()
{

}

void ArcadeScene::Init()
{
    ButtonAction action;
    action.key = GameController::actionKey();
    action.action = [](uint32_t dt, InputState state)
    {
        if(GameController::isPressed(state))
        {
            std::cout << "Action button was pressed!" << std::endl;
        }
    };

    this->gameController.AddInputActionForKey(action);

    MouseButtonAction mouseAction;
    mouseAction.mouseButton = GameController::LeftMouseButton();
    mouseAction.mouseInputAction = [](InputState state, const MousePosition& pos)
    {
        if(GameController::isPressed(state))
        {
            std::cout << "Left mouse button pressed!" << std::endl;
        }
    };
    this->gameController.AddMouseButtonAction(mouseAction);
    this->gameController.setMouseMovedAction([] (const MousePosition& mousePosition)
    {
        std::cout << "Mouse position x: " << mousePosition.xPos << ", Y:" << mousePosition.yPos << std::endl;
    });

    chess.Init(this->gameController);

    angle = 0.0f;
    result = 0;

    startX = SCREEN_WIDTH / 4;
    startY = SCREEN_HEIGHT / 2;

    endX = SCREEN_WIDTH / 2 + (SCREEN_WIDTH / 4);
    endY = SCREEN_HEIGHT / 2;

    cx = (startX + endX) / 2;
    cy = (startY + endY) / 2;

    tx = startX - cx;
    ty = startY - cy;

    tx2 = endX - cx;
    ty2 = endY - cy;

    line = {Vec2D(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2), Vec2D(SCREEN_WIDTH / 2 + (SCREEN_WIDTH / 4), SCREEN_HEIGHT / 2)};
}

void ArcadeScene::Update(uint32_t dt)
{

}

void ArcadeScene::Draw(Screen& screen)
{

    Star2D star = {Vec2D(screen.Width() / 2, 0), Vec2D(screen.Width() / 4, screen.Height())};

    Triangle triangle = {Vec2D(60,10), Vec2D(10,110), Vec2D(110,110)};

    AARectangle rect = {Vec2D(screen.Width()/2 - 25, screen.Height()/2 - 25), 50, 50};

    Circle circle = {Vec2D(screen.Width()/2 + 50, screen.Height()/2 + 50), 50};

    //chess.Draw(screen);

    screen.Draw(line, Color::White());
    screen.Draw(triangle, Color::Red(), true, Color::Red());
    screen.Draw(rect, Color::Blue(), true, Color::Blue());
    screen.Draw(circle, Color::Pink(), true, Color::Pink());

    angle += 1.0f;
    if(angle >= 360)
    {
        angle = 1.0f;
    }
    result = this->angle * (PI / 180.0); // angle in radians

    int rotX1 = (tx * cos(result)) + (ty * sin(result)) + cx;
    int rotY1 = (-tx * sin(result)) + (ty * cos(result)) + cy;

    int rotX2 = (tx2 * cos(result)) + (ty2 * sin(result)) + cx;
    int rotY2 = (-tx2 * sin(result)) + (ty2 * cos(result)) + cy;

    line.setStartPoint(Vec2D(rotX1, rotY1));
    line.setEndPoint(Vec2D(rotX2, rotY2));
}

const std::string ArcadeScene::GetSceneName() const
{
    static std::string sceneName = "Arcade Scene";
    return sceneName;
}

std::unique_ptr<Scene> ArcadeScene::GetScene(Games game)
{
    switch(game)
    {
        case TETRIS:
        {

        }
        break;

        case BREAK_OUT:
        {

        }
        break;

        case ASTEROIDS:
        {

        }
        break;

        case PACMAN:
        {

        }
        break;
        default:
        {

        }
        break;
    }

    return nullptr;
}
