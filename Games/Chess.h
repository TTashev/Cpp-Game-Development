#ifndef CHESS_H
#define CHESS_H

#include "Game.h"
#include "../Graphics/AARectangle.h"

struct chessTable
{
    AARectangle rect;
    std::vector<AARectangle> tiles;
};

struct pawn
{
    AARectangle verticalRect;
    AARectangle horizontalRect;
    AARectangle secondHorizontalRect;
    AARectangle upperHorizontalRect;
};

class Chess : public Game
{
public:
    Chess();
    void Init(GameController& controller) override;
    void Update(uint32_t dt) override;
    void Draw(Screen& screen) override;
    std::string GetName() const override;

private:
    chessTable table;
    pawn chessPawn;
};

#endif // CHESS_H
