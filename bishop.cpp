#include <iostream>
#include "pieces.h"

Bishop::Bishop(int row, int column, int color) : Piece(row, column, color) {
    setType(BISHOP);
    itMoved(false);
    setValue(3);
}

void Bishop::possibleSquares(Board matrix[][8]) {
    int firstDiagonalX = Column - 1;
    int firstDiagonalY = Row - 1;

    int secondDiagonalX = Column + 1;
    int secondDiagonalY = Row - 1;

    int thirdDiagonalX = Column + 1;
    int thirdDiagonalY = Row + 1;

    int forthDiagonalX = Column - 1;
    int forthDiagonalY = Row + 1;

    auto isEmpty = [&](int row, int column) {
        return matrix[row][column].piece == nullptr;
    };

    // FIRST DIAGONAL
    
    while (firstDiagonalX >= 0 && firstDiagonalY >= 0) {
        if (!isEmpty(firstDiagonalY, firstDiagonalX)) {
            break;
        }

        matrix[firstDiagonalY][firstDiagonalX].movable = true;

        firstDiagonalX--;
        firstDiagonalY--;
    }

    // SECOND DIAGONAL

    while (secondDiagonalX <= 7 && secondDiagonalY >= 0) {
        if (!isEmpty(secondDiagonalY, secondDiagonalX)) {
            break;
        }

        matrix[secondDiagonalY][secondDiagonalX].movable = true;

        secondDiagonalX++;
        secondDiagonalY--;
    }

    // THIRD DIAGONAL

    while (thirdDiagonalX <= 7 && thirdDiagonalY <= 7) {
        if (!isEmpty(thirdDiagonalY, thirdDiagonalX)) {
            break;
        }

        matrix[thirdDiagonalY][thirdDiagonalX].movable = true;

        thirdDiagonalX++;
        thirdDiagonalY++;
    }

    // FORTH DIAGONAL
    
    while (forthDiagonalX >= 0 && forthDiagonalY <= 7) {
        if (!isEmpty(forthDiagonalY, forthDiagonalX)) {
            break;
        }

        matrix[forthDiagonalY][forthDiagonalX].movable = true;

        forthDiagonalX--;
        forthDiagonalY++;
    }
}
