#include <iostream>
#include "pieces.h"

using namespace std;

#define BLACK -10
#define WHITE 10

#define FREE -1
#define KING 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5

Board board[8][8];

int main() {
    string boardPrint[8][8];

    int currentLetter = 97;
    int currentNumber = 8;

    for (int i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < 8; j++) {
                if (j % 2 == 0) {
                    board[i][j].color = WHITE;
                } else {
                    board[i][j].color = BLACK;
                }

                board[i][j].location = static_cast<char>(currentLetter) + to_string(currentNumber);
                currentLetter++;

            }
        } else {
            for (int j = 0; j < 8; j++) {
                if (j % 2 == 0) {
                    board[i][j].color = BLACK;
                } else {
                    board[i][j].color = WHITE;
                }

                board[i][j].location = static_cast<char>(currentLetter) + to_string(currentNumber);
                currentLetter++;
            }            
        }
        
        currentLetter = 97;
        currentNumber--;
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            boardPrint[i][j] = "□ ";
        }
    }

        for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j].piece = FREE;
        }
    }

    Rook test(7, 7, WHITE, board);
    Pawn test2(3, 7, WHITE, board);
    Queen test3(4, 7, WHITE, board);
    Pawn test4(6, 6, WHITE, board);

    // test.possibleSquares(boardPrint, board);
    test3.possibleSquares(boardPrint, board);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j].piece == QUEEN) {
                cout << "♕ ";
            } else if (board[i][j].piece == ROOK) {
                cout << "♖ ";
            } else if (board[i][j].piece == BISHOP) {
                cout << "♗ ";
            } else if (board[i][j].piece == KNIGHT) {
                cout << "♘ ";
            } else if (board[i][j].piece == PAWN) {
                cout << "♙ ";
            } else if (board[i][j].color == WHITE) {
                cout << "■ ";
            } else {
                cout << "□ ";
            }
        }

        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << boardPrint[i][j];
        }

        cout << endl;
    }
}