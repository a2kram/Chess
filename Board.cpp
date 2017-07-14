#include <stdexcept>
#include <iostream>

#include "Globals.h"
#include "Piece.h"
#include "Board.h"

void Board::MovePiece(Piece* Unit, uint8_t New_x, uint8_t New_y)
{
    if(Unit == NULL)
    {
        throw std::invalid_argument("Null piece");
        return;
    }
        
    uint8_t Old_x = Unit->GetX();
    uint8_t Old_y = Unit->GetY();

    if(Squares[Old_x + Old_y*X_LIMIT].Occupied)
    {
        if(Squares[New_x + New_y*X_LIMIT].Occupied)
        {
            if (Squares[Old_x + Old_y*X_LIMIT].PieceHere->GetColor() != Squares[New_x + New_y*X_LIMIT].PieceHere->GetColor())
            {
                Squares[New_x + New_y*X_LIMIT].PieceHere->KillPiece();
            }
        }

        Squares[Old_x + Old_y*X_LIMIT].PieceHere->MovePiece(New_x, New_y);
        Squares[Old_x + Old_y*X_LIMIT].Occupied = false;
    }

    Squares[New_x + New_y*X_LIMIT].Occupied = true;
    Squares[New_x + New_y*X_LIMIT].PieceHere = Unit;
}