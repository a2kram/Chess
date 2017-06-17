#ifndef GLOBALS_H
#define GLOBALS_H

#define X_LIMIT 8
#define Y_LIMIT 8

#define PLAYER_NUM_PIECES 16

#define HARD_DEPTH 5

#include <stdint.h>

enum PlayerColor
{
    White,
    Black,
    NoColor
};

enum PieceType
{
    Pawn, 
    Rock, 
    Knight,
    Bishop,
    King,
    Queen, 
    NoType
};

const PieceType Type[] = { Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Rock, Knight, Bishop, King, Queen, Bishop, Knight, Rock };
const uint8_t WhiteStartingX[] = { 0, 1 ,2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7 };
const uint8_t WhiteStartingY[] = { 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7 };
const uint8_t BlackStartingX[] = { 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7 };
const uint8_t BlackStartingY[] = { 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 };

#endif