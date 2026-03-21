#include <iostream>
#include "pieces.h"
#include "raylib.h"

using namespace std;

const Color boardGreen = {115, 149, 82, 255};
const Color boardWhite = {235, 236, 208, 255};
const Color background = {65, 65, 65, 255};
const Color lineColor = {255, 255, 255, 255};
const Color selected = {190, 156, 228, 255};

const int squareSize = 72;

bool whitesTurn = true;

Board board[8][8];

int main() {
    int currentLetter = 97;
    int currentNumber = 8;

    for (int i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < 8; j++) {
                if (j % 2 == 0) {
                    board[i][j].color = BRANCO;
                    board[i][j].drawColor = boardWhite;
                } else {
                    board[i][j].color = PRETO;
                    board[i][j].drawColor = boardGreen;
                }

                board[i][j].location = static_cast<char>(currentLetter) + to_string(currentNumber);
                currentLetter++;

            }
        } else {
            for (int j = 0; j < 8; j++) {
                if (j % 2 == 0) {
                    board[i][j].color = PRETO;
                    board[i][j].drawColor = boardGreen;
                } else {
                    board[i][j].color = BRANCO;
                    board[i][j].drawColor = boardWhite;
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
            board[i][j].piece = nullptr;
            board[i][j].movable = false;
        }
    }

    // Rook bRook1(0, 0, PRETO);
    // Knight bKnight1(0, 1, PRETO);
    // Bishop bBishop1(0, 2, PRETO);
    // Queen bQueen(0, 3, PRETO);
    // King bKing(0, 4, PRETO);
    // Bishop bBishop2(0, 5, PRETO);
    // Knight bKnight2(0, 6, PRETO);
    // Rook bRook2(0, 7, PRETO);
    
    // Pawn wPawn1(6, 0, BRANCO);
    // Pawn wPawn2(6, 1, BRANCO);
    // Pawn wPawn3(6, 2, BRANCO);
    // Pawn wPawn4(6, 3, BRANCO);
    // Pawn wPawn5(6, 4, BRANCO);
    // Pawn wPawn6(6, 5, BRANCO);
    // Pawn wPawn7(6, 6, BRANCO);
    // Pawn wPawn8(6, 7, BRANCO);

    // Rook wRook1(7, 0, BRANCO);
    // Knight wKnight1(7, 1, BRANCO);
    // Bishop wBishop1(7, 2, BRANCO);
    // Queen wQueen(7, 3, BRANCO);
    // King wKing(7, 4, BRANCO);
    // Bishop wBishop2(7, 5, BRANCO);
    // Knight wKnight2(7, 6, BRANCO);
    // Rook wRook2(7, 7, BRANCO);

    for (int i = 0; i < 8; i++) {
        board[1][i].piece = std::make_unique<Pawn>(1, i, PRETO);
    }

    for (int i = 0; i < 8; i++) {
        board[6][i].piece = std::make_unique<Pawn>(6, i, BRANCO);
    }

    board[0][1].piece = std::make_unique<Knight>(0, 1, PRETO);
    board[0][2].piece = std::make_unique<Bishop>(0, 2, PRETO);
    board[0][4].piece = std::make_unique<King>(0, 4, PRETO);
    board[0][5].piece = std::make_unique<Bishop>(0, 5, PRETO);
    board[0][6].piece = std::make_unique<Knight>(0, 6, PRETO);

    // board[0][0].piece = bRook1;
    // board[0][1].piece = bKnight1;
    // board[0][2].piece = bBishop1;
    // board[0][3].piece = bQueen;
    // board[0][4].piece = bKing;
    // board[0][5].piece = bBishop2;
    // board[0][6].piece = bKnight2;
    // board[0][7].piece = bRook2;

    // board[6][0].piece = wPawn1;
    // board[6][1].piece = wPawn2;
    // board[6][2].piece = wPawn3;
    // board[6][3].piece = wPawn4;
    // board[6][4].piece = wPawn5;
    // board[6][5].piece = wPawn6;
    // board[6][6].piece = wPawn7;
    // board[6][7].piece = wPawn8;

    // board[7][0].piece = wRook1;
    // board[7][1].piece = wKnight1;
    // board[7][2].piece = wBishop1;
    // board[7][3].piece = wQueen;
    // board[7][4].piece = wKing;
    // board[7][5].piece = wBishop2;
    // board[7][6].piece = wKnight2;
    // board[7][7].piece = wRook2;

    board[7][1].piece = std::make_unique<Knight>(7, 1, BRANCO);
    board[7][2].piece = std::make_unique<Bishop>(7, 2, BRANCO);
    board[7][4].piece = std::make_unique<King>(7, 4, BRANCO);
    board[7][5].piece = std::make_unique<Bishop>(7, 5, BRANCO);
    board[7][6].piece = std::make_unique<Knight>(7, 6, BRANCO);


    Rectangle squares[8][8];

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            squares[i][j] = {(float)(100 + j * squareSize), (float)(20 + i * squareSize), squareSize, squareSize};
        }
    }

    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Nychess");

    Texture2D whiteKing = LoadTexture("/home/nydawar/coding_stuff/chess/piece_images/white/white-king.png");
    Texture2D whitePawn = LoadTexture("/home/nydawar/coding_stuff/chess/piece_images/white/white-pawn.png");
    Texture2D whiteKnight = LoadTexture("/home/nydawar/coding_stuff/chess/piece_images/white/white-knight.png");
    Texture2D whiteBishop = LoadTexture("/home/nydawar/coding_stuff/chess/piece_images/white/white-bishop.png");
    Texture2D whiteRook = LoadTexture("/home/nydawar/coding_stuff/chess/piece_images/white/white-rook.png");
    Texture2D whiteQueen = LoadTexture("/home/nydawar/coding_stuff/chess/piece_images/white/white-queen.png");

    Texture2D blackKing = LoadTexture("/home/nydawar/coding_stuff/chess/piece_images/black/black-king.png");
    Texture2D blackPawn = LoadTexture("/home/nydawar/coding_stuff/chess/piece_images/black/black-pawn.png");
    Texture2D blackKnight = LoadTexture("/home/nydawar/coding_stuff/chess/piece_images/black/black-knight.png");
    Texture2D blackBishop = LoadTexture("/home/nydawar/coding_stuff/chess/piece_images/black/black-bishop.png");
    Texture2D blackRook = LoadTexture("/home/nydawar/coding_stuff/chess/piece_images/black/black-rook.png");
    Texture2D blackQueen = LoadTexture("/home/nydawar/coding_stuff/chess/piece_images/black/black-queen.png");

    Texture2D dot = LoadTexture("/home/nydawar/coding_stuff/chess/piece_images/dot.png");


    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

            ClearBackground(background);

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (board[i][j].color == BRANCO)
                        DrawRectangle(100 + (j * squareSize), 20 + (i * squareSize), squareSize, squareSize, board[i][j].drawColor);
                    
                    if (board[i][j].color == PRETO)
                        DrawRectangle(100 + (j * squareSize), 20 + (i * squareSize), squareSize, squareSize, board[i][j].drawColor);
                }
            }

            Vector2 mouse = GetMousePosition();

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (board[i][j].color == BRANCO)
                        board[i][j].drawColor = boardWhite;
                    
                    if (board[i][j].color == PRETO)
                        board[i][j].drawColor = boardGreen;

                    if (board[i][j].piece && board[i][j].piece->Selected == true)
                        board[i][j].drawColor = selected;

                    if (board[i][j].movable) {
                        DrawTexture(dot, squares[i][j].x, squares[i][j].y, WHITE);
                    }

                    if (CheckCollisionPointRec(mouse, squares[i][j])) {
                        if (!board[i][j].movable)
                            DrawRectangleRec(squares[i][j], board[i][j].drawColor);
                        
                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                            if (!board[i][j].piece) {
                                bool movedPiece = false;

                                for (int k = 0; k < 8 && !movedPiece; k++) {
                                    for (int l = 0; l < 8; l++) {
                                        if (board[k][l].piece && board[k][l].piece->Selected == true && board[i][j].movable) {
                                            board[k][l].piece->Row = i;
                                            board[k][l].piece->Column = j;
                                            board[i][j].piece = move(board[k][l].piece);
                                            board[i][j].piece->itMoved(true);
                                            board[i][j].piece->Selected = false;

                                            whitesTurn = !whitesTurn;
                                            movedPiece = true;
                                        }
                                    }
                                }

                                for (int k = 0; k < 8; k++) {
                                    for (int l = 0; l < 8; l++) {
                                        if (board[k][l].movable) 
                                            board[k][l].movable = false;

                                        if (board[k][l].piece && board[k][l].piece->Selected == true) 
                                            board[k][l].piece->Selected = false;
                                    }
                                }

                                continue;
                            }

                            if (whitesTurn && board[i][j].piece->Color == PRETO)
                                continue;

                            if (!whitesTurn && board[i][j].piece->Color == BRANCO)
                                continue;
                        
                            for (int k = 0; k < 8; k++) {
                                for (int l = 0; l < 8; l++) {
                                    if (board[k][l].movable) {
                                        board[k][l].movable = false;

                                        if (board[k][l].color == BRANCO)
                                            board[k][l].drawColor = boardWhite;
                                        else
                                            board[k][l].drawColor = boardGreen;
                                    }
                                }
                            }

                            if (board[i][j].piece->Selected == true) {
                                board[i][j].piece->Selected = false;
                                continue;
                            }

                            board[i][j].piece->possibleSquares(board);

                            for (int k = 0; k < 8; k++) {
                                for (int l = 0; l < 8; l++) {
                                    if (board[k][l].piece && board[k][l].piece->Selected == true)
                                        board[k][l].piece->Selected = false;

                                    // if (board[i][j].movable) {
                                    //     DrawTexture(dot, squares[i][j].x, squares[i][j].y, WHITE);
                                    // }
                                }
                            }

                            board[i][j].piece->Selected = true;    
                            board[i][j].drawColor = selected;
                        }
                    }

                    // for (int k = 0; k < 8; k++) {
                    //     for (int l = 0; l < 8; l++) {
                    //         if (board[k][l].piece && board[k][l].piece->Selected == true)
                    //             continue;

                    //         if (board[k][l].movable)
                    //             continue;

                    //         if (board[k][l].color == BRANCO)
                    //             board[k][l].drawColor = boardWhite;
                    //         else
                    //             board[k][l].drawColor = boardGreen;
                    //     }
                    // }
                }
            }

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {

                    // WHITE PIECES

                    if (board[i][j].piece && board[i][j].piece->Type == KING && board[i][j].piece->Color == BRANCO) {
                        DrawTexture(whiteKing, squares[i][j].x, squares[i][j].y, WHITE);
                    }

                    if (board[i][j].piece && board[i][j].piece->Type == PAWN && board[i][j].piece->Color == BRANCO) {
                        DrawTexture(whitePawn, squares[i][j].x, squares[i][j].y, WHITE);
                    }

                    if (board[i][j].piece && board[i][j].piece->Type == KNIGHT && board[i][j].piece->Color == BRANCO) {
                        DrawTexture(whiteKnight, squares[i][j].x, squares[i][j].y, WHITE);
                    }

                    if (board[i][j].piece && board[i][j].piece->Type == BISHOP && board[i][j].piece->Color == BRANCO) {
                        DrawTexture(whiteBishop, squares[i][j].x, squares[i][j].y, WHITE);
                    }

                    if (board[i][j].piece && board[i][j].piece->Type == ROOK && board[i][j].piece->Color == BRANCO) {
                        DrawTexture(whiteRook, squares[i][j].x, squares[i][j].y, WHITE);
                    }

                    if (board[i][j].piece && board[i][j].piece->Type == QUEEN && board[i][j].piece->Color == BRANCO) {
                        DrawTexture(whiteQueen, squares[i][j].x, squares[i][j].y, WHITE);
                    }

                    // BLACK PIECES

                    if (board[i][j].piece && board[i][j].piece->Type == KING && board[i][j].piece->Color == PRETO) {
                        DrawTexture(blackKing, squares[i][j].x, squares[i][j].y, WHITE);
                    }

                    if (board[i][j].piece && board[i][j].piece->Type == PAWN && board[i][j].piece->Color == PRETO) {
                        DrawTexture(blackPawn, squares[i][j].x, squares[i][j].y, WHITE);
                    }

                    if (board[i][j].piece && board[i][j].piece->Type == KNIGHT && board[i][j].piece->Color == PRETO) {
                        DrawTexture(blackKnight, squares[i][j].x, squares[i][j].y, WHITE);
                    }

                    if (board[i][j].piece && board[i][j].piece->Type == BISHOP && board[i][j].piece->Color == PRETO) {
                        DrawTexture(blackBishop, squares[i][j].x, squares[i][j].y, WHITE);
                    }

                    if (board[i][j].piece && board[i][j].piece->Type == ROOK && board[i][j].piece->Color == PRETO) {
                        DrawTexture(blackRook, squares[i][j].x, squares[i][j].y, WHITE);
                    }

                    if (board[i][j].piece && board[i][j].piece->Type == QUEEN && board[i][j].piece->Color == PRETO) {
                        DrawTexture(blackQueen, squares[i][j].x, squares[i][j].y, WHITE);
                    }
                }
            }

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    // if
                }
            }
            
            // DrawLineEx((Vector2){100, 20}, (Vector2){612, 20}, 6.0, lineColor);
            // DrawLineEx((Vector2){100, 17}, (Vector2){100, 538}, 6.0, lineColor);
            // DrawLineEx((Vector2){100, 535}, (Vector2){612, 535}, 6.0, lineColor);
            // DrawLineEx((Vector2){612, 17}, (Vector2){612, 538}, 6.0, lineColor);

        EndDrawing();
    }

    CloseWindow();  
    
    return 0;
}
