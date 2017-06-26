#ifndef GAME_H
#define GAME_H

#include "Globals.h"
#include "Piece.h"
#include "Player.h"
#include "Graphics.h"
#include "Board.h"

class Game
{

public:
    Game(void);
    void MovePiece(uint8_t Old_x, uint8_t Old_y, uint8_t New_x, uint8_t New_y);

private:
    void InitializeBoard(void);
    void NextTurn(void);
    bool IsGameOver(void);

    PlayerColor _Winner;
    PlayerColor _Turn;

    Piece       _PlayerArray[2][PLAYER_NUM_PIECES];

    Player      _PlayerWhite;
    Player      _PlayerBlack;

    Graphics    _Graphics;

    Board       _Board;
};

#endif