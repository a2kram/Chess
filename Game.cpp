#include <unistd.h>
#include <iostream>

#include "Globals.h"
#include "Game.h"
#include "Player.h"
#include "Piece.h"
#include "Graphics.h"
#include "Board.h"

using namespace std;

Game::Game(void) 
    : _Winner(NoColor), _Turn(White)
{
    _PlayerWhite = Player("WhitePlayer", White);
    _PlayerBlack = Player("BlackPlayer", Black);
    _Graphics = Graphics();

    InitializeBoard();

    while (!IsGameOver())
    {
        NextTurn();
        _Graphics.Update(_Board);
    }

    return;
}

bool Game::IsGameOver(void) { return false; }

void Game::NextTurn(void)
{
    if (_Turn == White)
    {
        _PlayerWhite.Move(HARD_DEPTH, &_Board, _PlayerArray[White]);
        _Turn = Black;
    }
    else
    {
        _PlayerBlack.Move(HARD_DEPTH, &_Board, _PlayerArray[Black]);
        _Turn = White;
    }

    sleep(1);
}

void Game::InitializeBoard(void)
{
    for (int i = 0; i < PLAYER_NUM_PIECES; ++i)
    {
        _PlayerArray[White][i] = Piece(Type[i], WhiteStartingX[i], WhiteStartingY[i], White, this);
        _PlayerArray[Black][i] = Piece(Type[i], BlackStartingX[i], BlackStartingY[i], Black, this);
    }
}

void Game::MovePiece(Piece* Unit, uint8_t New_x, uint8_t New_y)
{
    _Board.MovePiece(Unit, New_x, New_y);
}