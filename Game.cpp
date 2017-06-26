#include "Globals.h"
#include "Game.h"
#include "Player.h"
#include "Piece.h"
#include "Graphics.h"
#include "Board.h"

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
}

void Game::InitializeBoard(void)
{
    for (int i = 0; i < PLAYER_NUM_PIECES; ++i)
    {
        _PlayerArray[White][i] = Piece(Type[i], WhiteStartingX[i], WhiteStartingY[i], White, this);
        _PlayerArray[Black][i] = Piece(Type[i], BlackStartingX[i], BlackStartingY[i], Black, this);

        _Board.Squares[WhiteStartingX[i] + WhiteStartingY[i] * X_LIMIT].Occupied = true;
        _Board.Squares[WhiteStartingX[i] + WhiteStartingY[i] * X_LIMIT].PieceHere = &_PlayerArray[White][i];

        _Board.Squares[BlackStartingX[i] + BlackStartingY[i] * X_LIMIT].Occupied = true;
        _Board.Squares[BlackStartingX[i] + BlackStartingY[i] * X_LIMIT].PieceHere = &_PlayerArray[Black][i];;
    }
}

void Game::MovePiece(uint8_t Old_x, uint8_t Old_y, uint8_t New_x, uint8_t New_y)
{
    _Board.MovePiece(Old_x, Old_y, New_x, New_y);
}