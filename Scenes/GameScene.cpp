#include "GameScene.h"

GameScene::GameScene(std::unique_ptr<Game> gamePtr) : game(std::move(gamePtr))
{

}

GameScene::~GameScene()
{

}


void GameScene::Init()
{
    game->Init(gameController);
}

void GameScene::Update(uint32_t dt)
{
    game->Update(dt);
}

void GameScene::Draw(Screen& screen)
{
    game->Draw(screen);
}


const std::string GameScene::GetSceneName() const
{
    static std::string name = "";
    return name;
}
