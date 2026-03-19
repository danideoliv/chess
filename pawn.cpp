#include <iostream>
#include "pieces.h"

Pawn::Pawn(int row, int column, int color, Board board[][8]) : Piece(row, column, color, board) {
    setType(PAWN);
    board[Row][Column].piece = PAWN;
    itMoved(false);
    setValue(1);
}

void Pawn::possibleSquares(string matrix[][8], Board matrix2[][8]) {
    int pawnY = Row;
    int pawnX = Column;

    if (Moved == false) {
        if (Color == WHITE) {
            if (matrix2[pawnY - 2][pawnX].piece == FREE && matrix2[pawnY - 1][pawnX].piece == FREE) {
                matrix[pawnY - 1][pawnX] = "■ ";
                matrix[pawnY - 2][pawnX] = "■ ";
            } else if (matrix2[pawnY - 1][pawnX].piece == FREE) {
                matrix[pawnY - 1][pawnX] = "■ ";
            }
        } else {
            if (matrix2[pawnY + 2][pawnX].piece == FREE && matrix2[pawnY + 1][pawnX].piece == FREE) {
                matrix[pawnY + 1][pawnX] = "■ ";
                matrix[pawnY + 2][pawnX] = "■ ";
            } else if (matrix2[pawnY - 1][pawnX].piece == FREE) {
                matrix[pawnY + 1][pawnX] = "■ ";
            }
        }
    } else {
        if (Color == WHITE) {
            if (matrix2[pawnY - 1][pawnX].piece == FREE)
                matrix[pawnY - 1][pawnX] = "■ ";
        } else {
            if (matrix2[pawnY + 1][pawnX].piece == FREE)
                matrix[pawnY + 1][pawnX] = "■ ";
        }
    }

    if (Color == WHITE) {
        if (matrix2[pawnY - 1][pawnX + 1].piece != FREE && Color != matrix2[pawnY - 1][pawnX + 1].piece_color) {
            // Farei algo
        }

        if (matrix2[pawnY - 1][pawnX - 1].piece != FREE && Color != matrix2[pawnY - 1][pawnX - 1].piece_color) {
            // Farei algo
        }
    }

    if (Color == WHITE) {
        if (matrix2[pawnY + 1][pawnX + 1].piece != FREE && Color != matrix2[pawnY + 1][pawnX + 1].piece_color) {
            // Farei algo
        }

        if (matrix2[pawnY + 1][pawnX - 1].piece != FREE && Color != matrix2[pawnY + 1][pawnX - 1].piece_color) {
            // Farei algo
        }
    }
}