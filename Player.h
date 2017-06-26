#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Globals.h"
#include "Piece.h"
#include "Board.h"

using namespace std;

typedef struct _Move
{
    uint8_t oldx;
    uint8_t oldy;
    uint8_t newx;
    uint8_t newy;
    Piece*  piece;
}MoveType;

class Player
{

public:
    Player();
    Player(std::string Name, PlayerColor Color);
    void Move(uint8_t Depth, Board* StartingBoard, Piece Pieces[PLAYER_NUM_PIECES]);

private:
    bool CheckLegalMove(uint8_t x, uint8_t y, Board CurrBoard);
    uint32_t Evaluate(Board CurrBoard, MoveType CurrMove);

    std::string _Name;
    PlayerColor _Color;

};

#endif