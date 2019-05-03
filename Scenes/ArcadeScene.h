#ifndef ARCADESCENE_H_
#define ARCADESCENE_H_

#include "Scene.h"
#include "../Graphics/Line2D.h"
#include <memory>


enum Game
{
    TETRIS = 0,
    BREAK_OUT,
    ASTEROIDS,
    PACMAN,
    NUM_GAMES
};

class Screen;

class ArcadeScene : public Scene
{
public:
    ArcadeScene();
    virtual void Init() override;
    virtual void Update(uint32_t dt) override;
    virtual void Draw(Screen& screen) override;
    virtual const std::string GetSceneName() const override;

private:
    std::unique_ptr<Scene> GetScene(Game game);

    double angle;
    double result;

    int startX;
    int startY;

    int endX;
    int endY;

    int cx;
    int cy;

    int tx;
    int ty;

    int tx2;
    int ty2;

    class Line2D line;
};

#endif // ARCADESCENE_H_
