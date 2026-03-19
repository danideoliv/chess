#include <iostream>
#include "pieces.h"

Knight::Knight(int row, int column, int color, Board board[][8]) : Piece(row, column, color, board) {
    setType(KNIGHT);
    board[Row][Column].piece = KNIGHT;
    itMoved(false);
    setValue(3);
}

void Knight::possibleSquares(string matrix[][8], Board matrix2[][8]) {
    int knightX = Column;
    int knightY = Row;

    // UP SIDE
    
    if (knightY - 2 >= 0) {
        if (knightX - 1 >= 0) {
            if (matrix2[knightY - 2][knightX - 1].piece != FREE && Color != matrix2[knightY - 2][knightX - 1].piece_color) {
                // Farei algo
            } else if (matrix2[knightY - 2][knightX - 1].piece == FREE) {
                matrix[knightY - 2][knightX - 1] = "■ ";
            }
        }

        if (knightX + 1 <= 7) {
            if (matrix2[knightY - 2][knightX + 1].piece != FREE && Color != matrix2[knightY - 2][knightX + 1].piece_color) {
                // Farei algo
            } else if (matrix2[knightY - 2][knightX + 1].piece == FREE) {
                matrix[knightY - 2][knightX + 1] = "■ ";
            }
        }
    }

    // RIGHT SIDE
    
    if (knightX + 2 <= 7) {
        if (knightY - 1 >= 0) {
            if (matrix2[knightY - 1][knightX + 2].piece != FREE && Color != matrix2[knightY - 1][knightX + 2].piece_color) {
                // Farei algo
            } else if (matrix2[knightY - 1][knightX + 2].piece == FREE) {
                matrix[knightY - 1][knightX + 2] = "■ ";
            }
        }

        if (knightY + 1 <= 7) {
            if (matrix2[knightY + 1][knightX + 2].piece != FREE && Color != matrix2[knightY + 1][knightX + 2].piece_color) {
                // Farei algo
            } else if (matrix2[knightY + 1][knightX + 2].piece == FREE) {
                matrix[knightY + 1][knightX + 2] = "■ ";
            }
        }
    }

    // DOWN SIDE
    
    if (knightY + 2 <= 7) {
        if (knightX - 1 >= 0) {
            if (matrix2[knightY + 2][knightX - 1].piece != FREE && Color != matrix2[knightY + 2][knightX - 1].piece_color) {
                // Farei algo
            } else if (matrix2[knightY + 2][knightX - 1].piece == FREE) {
                matrix[knightY + 2][knightX - 1] = "■ ";
            }
        }

        if (knightX + 1 <= 7) {
            if (matrix2[knightY + 2][knightX + 1].piece != FREE && Color != matrix2[knightY + 2][knightX + 1].piece_color) {
                // Farei algo
            } else if (matrix2[knightY + 2][knightX + 1].piece == FREE) {
                matrix[knightY + 2][knightX + 1] = "■ ";
            }
        }
    }

    // LEFT SIDE
    
    if (knightX - 2 >= 0) {
        if (knightY - 1 >= 0) {
            if (matrix2[knightY - 1][knightX - 2].piece != FREE && Color != matrix2[knightY - 1][knightX - 2].piece_color) {
                // Farei algo
            } else if (matrix2[knightY - 1][knightX - 2].piece == FREE) {
                matrix[knightY - 1][knightX - 2] = "■ ";
            }
        }

        if (knightY + 1 <= 7) {
            if (matrix2[knightY + 1][knightX - 2].piece != FREE && Color != matrix2[knightY + 1][knightX - 2].piece_color) {
                // Farei algo
            } else if (matrix2[knightY + 1][knightX - 2].piece == FREE) {
                matrix[knightY + 1][knightX - 2] = "■ ";
            }
        }
    }
}