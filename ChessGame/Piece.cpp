#include <stdint.h>
#include <stdexcept>

#include "Globals.h"
#include "Piece.h"
#include "Game.h"

Piece::Piece(){}

Piece::Piece(PieceType Type, uint8_t x, uint8_t y, PlayerColor Color, Game* GameObj)
    : _Type(Type), _Alive(true), _Color(Color)
{
    if (x > X_LIMIT || y > Y_LIMIT)
    {
        throw std::invalid_argument("Invalid x and y location");
        return;
    }

    _x = x;
    _y = y;

    GameObj->MovePiece(_x, _y, x, y);
}

void Piece::KillPiece(void)
{
    _Alive = false;
}

bool Piece::MovePiece(uint8_t x, uint8_t y)
{
    if (x > X_LIMIT || y > Y_LIMIT)
    {
        return false;
    }

    _x = x;
    _y = y;

    return true;
}

uint8_t Piece::GetX()
{
    return _x;
}

uint8_t Piece::GetY()
{
    return _y;
}

PieceType Piece::GetType()
{
    return _Type;
}

PlayerColor Piece::GetColor()
{
    return _Color;
}