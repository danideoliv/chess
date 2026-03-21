#include <iostream>
#include "pieces.h"

Queen::Queen(int row, int column, int color) : Piece(row, column, color) {
    setType(QUEEN);
    itMoved(false);
    setValue(9);
}

void Queen::possibleSquares(string matrix[][8], Board matrix2[][8]) {
    // CROSS

    int firstLineX = Column;
    int firstLineY = Row - 1;

    int secondLineX = Column + 1;
    int secondLineY = Row;

    int thirdLineX = Column;
    int thirdLineY = Row + 1;

    int forthLineX = Column - 1;
    int forthLineY = Row;

    // UP LINE

    while (firstLineY >= 0) {
        if (matrix2[firstLineY][firstLineX].piece.Type != FREE && Color == matrix2[firstLineY][firstLineX].piece_color) {
            break;
        }

        matrix[firstLineY][firstLineX] = "■ ";

        firstLineY--;
    }

    // RIGHT LINE

    while (secondLineX <= 7) {
        if (matrix2[secondLineY][secondLineX].piece.Type != FREE && Color == matrix2[secondLineY][secondLineX].piece_color) {
            break;
        }

        matrix[secondLineY][secondLineX] = "■ ";

        secondLineX++;
    }

    // DOWN LINE

    while (thirdLineY <= 7) {
        if (matrix2[thirdLineY][thirdLineX].piece.Type != FREE && Color == matrix2[thirdLineY][thirdLineX].piece_color) {
            break;
        }

        matrix[thirdLineY][thirdLineX] = "■ ";

        thirdLineY++;
    }

    // LEFT LINE

    while (forthLineX >= 0) {
        if (matrix2[forthLineY][forthLineX].piece.Type != FREE && Color == matrix2[forthLineY][forthLineX].piece_color) {
            break;
        }

        matrix[forthLineY][forthLineX] = "■ ";

        forthLineX--;
    }

    // X

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
        if (matrix2[firstDiagonalY][firstDiagonalX].piece.Type != FREE && Color == matrix2[firstDiagonalY][firstDiagonalX].piece_color) {
            break;
        }

        matrix[firstDiagonalY][firstDiagonalX] = "■ ";

        firstDiagonalX--;
        firstDiagonalY--;
    }

    // SECOND DIAGONAL

    while (secondDiagonalX <= 7 && secondDiagonalY >= 0) {
        if (matrix2[secondDiagonalY][secondDiagonalX].piece.Type != FREE && Color == matrix2[secondDiagonalY][secondDiagonalX].piece_color) {
            break;
        }

        matrix[secondDiagonalY][secondDiagonalX] = "■ ";

        secondDiagonalX++;
        secondDiagonalY--;
    }

    // THIRD DIAGONAL

    while (thirdDiagonalX <= 7 && thirdDiagonalY <= 7) {
        if (matrix2[thirdDiagonalY][thirdDiagonalX].piece.Type != FREE && Color == matrix2[thirdDiagonalY][thirdDiagonalX].piece_color) {
            break;
        }

        matrix[thirdDiagonalY][thirdDiagonalX] = "■ ";

        thirdDiagonalX++;
        thirdDiagonalY++;
    }

    // FORTH DIAGONAL
    
    while (forthDiagonalX >= 0 && forthDiagonalY <= 7) {
        if (matrix2[forthDiagonalY][forthDiagonalX].piece.Type != FREE && Color == matrix2[forthDiagonalY][forthDiagonalX].piece_color) {
            break;
        }

        matrix[forthDiagonalY][forthDiagonalX] = "■ ";

        forthDiagonalX--;
        forthDiagonalY++;
    }
}
