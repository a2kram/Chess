#include <string>
#include <vector>

#include "Globals.h"
#include "Player.h"
#include "Piece.h"
#include "Game.h"
#include "Board.h"

using namespace std;

Player::Player(){}

Player::Player(std::string Name, PlayerColor Color)
    : _Name(Name), _Color(Color) {}

void Player::Move(uint8_t Depth, Board* StartingBoard, Piece Pieces[PLAYER_NUM_PIECES])
{
    vector<MoveType> PossibleMoves;
    int8_t Direction = (_Color == White) ? -1 : 1;
    uint32_t MaxScore = 0;
    uint32_t Score;
    MoveType NewMove = { 0 };
    MoveType* BestMove;

    for (uint8_t i = 0; i < PLAYER_NUM_PIECES; ++i)
    {
        uint8_t x = Pieces[i].GetX();
        uint8_t y = Pieces[i].GetY();

        switch (Pieces[i].GetType())
        {
        case Pawn:
            if (CheckLegalMove(x, y + (1 * Direction), *StartingBoard))
            {
                NewMove.oldx = x;
                NewMove.oldy = y;
                NewMove.newx = x;
                NewMove.newy = y + (1 * Direction);
                NewMove.piece = &Pieces[i];

                PossibleMoves.push_back(NewMove);
            }
            
            if (((y == WhiteStartingY[0]) && (_Color == White))
                || ((y == BlackStartingY[0]) && (_Color == Black)))
            {
                if (CheckLegalMove(x, y + (2 * Direction), *StartingBoard))
                {
                    NewMove.oldx = x;
                    NewMove.oldy = y;
                    NewMove.newx = x;
                    NewMove.newy = y + (2 * Direction);
                    NewMove.piece = &Pieces[i];

                    PossibleMoves.push_back(NewMove);
                }
            }
            break;
        case Rock:
            break;
        case Knight:
            break;
        case Bishop:
            break;
        case King:
            break;
        case Queen:
            break;
        case NoType:
        default:
            break;
        }
    }

    for (uint32_t i = 0; i < PossibleMoves.size(); ++i)
    {
        Score = Evaluate(*StartingBoard, PossibleMoves[i]);

        if (Score >= MaxScore)
        {
            BestMove = &PossibleMoves[i];
            MaxScore = Score;
        }
    }

    StartingBoard->MovePiece(BestMove->oldx, BestMove->oldy, BestMove->newx, BestMove->newy);
    BestMove->piece->MovePiece(BestMove->newx, BestMove->newy);
}

bool Player::CheckLegalMove(uint8_t x, uint8_t y, Board CurrBoard)
{
    if (x >= X_LIMIT || y >= Y_LIMIT)
    {
        return false;
    }

    if (CurrBoard.Squares[x + y * X_LIMIT].Occupied  && CurrBoard.Squares[x + y * X_LIMIT].PieceHere->GetColor() == _Color)
    {
        return false;
    }

    return true;
}

uint32_t Player::Evaluate(Board CurrBoard, MoveType CurrMove)
{
    uint32_t Score = 0; 

    for (uint8_t i = 0; i < (X_LIMIT * Y_LIMIT); ++i)
    {
        if (CurrBoard.Squares[i].PieceHere->GetColor() == _Color)
        {
            Score++;
        }
    }

    return Score;
}