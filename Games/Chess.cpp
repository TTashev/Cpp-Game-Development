#include "Chess.h"
#include "../include/Screen.h"

#define CHESS_WIDTH 520
#define CHESS_HEIGHT 520

Chess::Chess()
{

}

void Chess::Init(GameController& controller)
{
    table.rect = {Vec2D(140, 60), CHESS_WIDTH, CHESS_HEIGHT};
    table.tiles.resize(32);

    chessPawn.verticalRect = {Vec2D(165, 1), 10, 50};
    chessPawn.horizontalRect = {Vec2D(150, 50), 40, 10};
    chessPawn.secondHorizontalRect = {Vec2D(155, 35), 30, 15};
    chessPawn.upperHorizontalRect = {Vec2D(155, 8), 30, 15};

    int x = 140;
    int y = 60;

    int tile = 0;
    for(int row = 0; row < 4; row++)
    {
        for(int i = 1; i < 5; i++)
        {
            table.tiles[tile] = {Vec2D(x, y), CHESS_WIDTH / 8, CHESS_HEIGHT / 8};
            tile++;
            x += (CHESS_WIDTH / 8) * 2;
        }

        x = 140 + CHESS_WIDTH / 8;
        y += CHESS_WIDTH / 8;

        for(int i = 5; i < 9; i++)
        {
            table.tiles[tile] = {Vec2D(x, y), CHESS_WIDTH / 8, CHESS_HEIGHT / 8};
            tile++;
            x += (CHESS_WIDTH / 8) * 2;
        }
        x = 140;
        y += CHESS_WIDTH / 8;
    }

}

void Chess::Update(uint32_t dt)
{

}

void Chess::Draw(Screen& screen)
{
    screen.Draw(table.rect, Color::White());

    screen.Draw(chessPawn.verticalRect, Color::Black(), true, Color::White());
    screen.Draw(chessPawn.horizontalRect, Color::Black(), true, Color::White());
    screen.Draw(chessPawn.secondHorizontalRect, Color::Black(), true, Color::White());
    screen.Draw(chessPawn.upperHorizontalRect, Color::Black(), true, Color::White());

    for(auto& tile : table.tiles)
    {
        screen.Draw(tile, Color::White(), true);
    }

}

std::string Chess::GetName() const
{

}
