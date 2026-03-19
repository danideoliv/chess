#include <iostream>
#include "pieces.h"

Bishop::Bishop(int row, int column, int color, Board board[][8]) : Piece(row, column, color, board) {
    setType(BISHOP);
    board[Row][Column].piece = BISHOP;
    itMoved(false);
    setValue(3);
}

void Bishop::possibleSquares(string matrix[][8], Board matrix2[][8]) {
    int firstDiagonalX = Column - 1;
    int firstDiagonalY = Row - 1;

    int secondDiagonalX = Column + 1;
    int secondDiagonalY = Row - 1;

    int thirdDiagonalX = Column + 1;
    int thirdDiagonalY = Row + 1;

    int forthDiagonalX = Column - 1;
    int forthDiagonalY = Row + 1;

    // FIRST DIAGONAL
    
    while (firstDiagonalX >= 0 && firstDiagonalY >= 0) {
        if (matrix2[firstDiagonalY][firstDiagonalX].piece != FREE && Color == matrix2[firstDiagonalY][firstDiagonalX].piece_color) {
            break;
        }

        matrix[firstDiagonalY][firstDiagonalX] = "■ ";

        firstDiagonalX--;
        firstDiagonalY--;
    }

    // SECOND DIAGONAL

    while (secondDiagonalX <= 7 && secondDiagonalY >= 0) {
        if (matrix2[secondDiagonalY][secondDiagonalX].piece != FREE && Color == matrix2[secondDiagonalY][secondDiagonalX].piece_color) {
            break;
        }

        matrix[secondDiagonalY][secondDiagonalX] = "■ ";

        secondDiagonalX++;
        secondDiagonalY--;
    }

    // THIRD DIAGONAL

    while (thirdDiagonalX <= 7 && thirdDiagonalY <= 7) {
        if (matrix2[thirdDiagonalY][thirdDiagonalX].piece != FREE && Color == matrix2[thirdDiagonalY][thirdDiagonalX].piece_color) {
            break;
        }

        matrix[thirdDiagonalY][thirdDiagonalX] = "■ ";

        thirdDiagonalX++;
        thirdDiagonalY++;
    }

    // FORTH DIAGONAL
    
    while (forthDiagonalX >= 0 && forthDiagonalY <= 7) {
        if (matrix2[forthDiagonalY][forthDiagonalX].piece != FREE && Color == matrix2[forthDiagonalY][forthDiagonalX].piece_color) {
            break;
        }

        matrix[forthDiagonalY][forthDiagonalX] = "■ ";

        forthDiagonalX--;
        forthDiagonalY++;
    }
}
