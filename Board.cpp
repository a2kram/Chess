#include "Globals.h"
#include "Piece.h"
#include "Board.h"

void Board::MovePiece(uint8_t Old_x, uint8_t Old_y, uint8_t New_x, uint8_t New_y)
{
    if (Squares[Old_x + Old_y*X_LIMIT].PieceHere->GetColor() != Squares[New_x + New_y*X_LIMIT].PieceHere->GetColor())
    {
        Squares[New_x + New_y*X_LIMIT].PieceHere->KillPiece();
    }

    Squares[Old_x + Old_y*X_LIMIT].PieceHere->MovePiece(New_x, New_y);
    Squares[New_x + New_y*X_LIMIT].Occupied = true;
    Squares[Old_x + Old_y*X_LIMIT].Occupied = false;
}