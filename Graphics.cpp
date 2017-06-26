#include <iostream>
#include <windows.h>
#include "Graphics.h"
#include "Game.h"
#include "Board.h"

using namespace std;

Graphics::Graphics(void) : 
    _Turn(0)
{
    
}

void Graphics::Update(Board CurrBoard)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO Info;
    GetConsoleScreenBufferInfo(hConsole, &Info);
    WORD Attributes = Info.wAttributes;

    _Turn++;

    cout << "*******************************************************" << endl;
    cout << "                   CHESS - TURN # " << _Turn << endl;
    cout << "*******************************************************" << endl;
    cout << endl << "***|-----|-----|-----|-----|-----|-----|-----|-----|***" << endl << endl;

    for (uint8_t y = 0; y < X_LIMIT; ++y)
    {
        cout << "***";

        for (uint8_t x = 0; x < Y_LIMIT; ++x)
        {
            if (CurrBoard.Squares[x + y*X_LIMIT].Occupied)
            {
                SetConsoleTextAttribute(hConsole, Attributes);

                cout << "|";

                if (CurrBoard.Squares[x + y*X_LIMIT].PieceHere->GetColor() == White)
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                else if (CurrBoard.Squares[x + y*X_LIMIT].PieceHere->GetColor()== Black)
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                }

                switch (CurrBoard.Squares[x + y * X_LIMIT].PieceHere->GetType())
                {
                case Pawn:
                    cout << "  P  ";
                    break;

                case Rock:
                    cout << "  R  ";
                    break;

                case Knight:
                    cout << "  K  ";
                    break;

                case Bishop:
                    cout << "  B  ";
                    break;

                case King:
                    cout << " -K- ";
                    break;

                case Queen:
                    cout << "  Q  ";
                    break;

                default:
                    cout << "|  .  ";
                }
            }
            else
            {
                cout << "|  .  ";
            }

        }

        SetConsoleTextAttribute(hConsole, Attributes);

        cout << "|***" << endl;
        cout << endl << "***|-----|-----|-----|-----|-----|-----|-----|-----|***" << endl << endl;
    }

    cout << "*******************************************************" << endl;
    cout << "*******************************************************" << endl;
    cout << "*******************************************************" << endl;

    cout << endl;
    cout << endl;
    cout << endl;
}
