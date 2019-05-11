#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <memory>
#include "Scene.h"
#include "../Games/Game.h"

class GameScene : public Scene
{
public:
    GameScene(std::unique_ptr<Game> gamePtr);
    virtual ~GameScene();
    virtual void Init() override;
    virtual void Update(uint32_t dt) override;
    virtual void Draw(Screen& screen) override;

    virtual const std::string GetSceneName() const override;

private:
    std::unique_ptr<Game> game;
};

#endif // GAMESCENE_H
