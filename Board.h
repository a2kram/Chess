#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include "Globals.h"
#include "Piece.h"

typedef struct _Square
{
    bool   Occupied = false;
    Piece* PieceHere = NULL;
} Square;

class Board
{

public:
    void MovePiece(Piece* Unit, uint8_t New_x, uint8_t New_y);

    Square Squares[X_LIMIT*Y_LIMIT];
    
private:

};

#endif