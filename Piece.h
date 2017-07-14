#ifndef PIECE_H
#define PIECE_H

#include <stdint.h>
#include "Globals.h"

class Game;

class Piece
{

public:
    Piece();
    Piece(PieceType Type, uint8_t x, uint8_t y, PlayerColor Color, Game* GameObj);

    void KillPiece();
    bool MovePiece(uint8_t x, uint8_t y);
    bool ChangeType(PieceType Type);
    uint8_t GetX();
    uint8_t GetY();
    PieceType GetType();
    PlayerColor GetColor();
    bool IsAlive();

private: 
    PieceType   _Type;
    bool        _Alive;
    PlayerColor _Color;
    uint8_t     _x;
    uint8_t     _y;

};

#endif