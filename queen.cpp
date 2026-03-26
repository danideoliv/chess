#include <iostream>
#include "pieces.h"

Queen::Queen(int row, int column, int color) : Piece(row, column, color) {
    setType(QUEEN);
    itMoved(false);
    setValue(9);
}

void Queen::possibleSquares(Board matrix[][8]) {
    auto isEmpty = [&](int row, int column) {
        return matrix[row][column].piece == nullptr;
    };

    auto hasEnemyPiece = [&](int row, int column) {
        return matrix[row][column].piece != nullptr && Color != matrix[row][column].piece->Color;
    };

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
        if (hasEnemyPiece(firstLineY, firstLineX)) {
            matrix[firstLineY][firstLineX].piece->Threatened = true;
            break;
        }

        if (!isEmpty(firstLineY, firstLineX)) {
            break;
        }

        matrix[firstLineY][firstLineX].movable = true;

        firstLineY--;
    }

    // RIGHT LINE

    while (secondLineX <= 7) {
        if (hasEnemyPiece(secondLineY, secondLineX)) {
            matrix[secondLineY][secondLineX].piece->Threatened = true;
            break;
        }

        if (!isEmpty(secondLineY, secondLineX)) {
            break;
        }

        matrix[secondLineY][secondLineX].movable = true;

        secondLineX++;
    }

    // DOWN LINE

    while (thirdLineY <= 7) {
        if (hasEnemyPiece(thirdLineY, thirdLineX)) {
            matrix[thirdLineY][thirdLineX].piece->Threatened = true;
            break;
        }

        if (!isEmpty(thirdLineY, thirdLineX)) {
            break;
        }

        matrix[thirdLineY][thirdLineX].movable = true;

        thirdLineY++;
    }

    // LEFT LINE

    while (forthLineX >= 0) {
        if (hasEnemyPiece(forthLineY, forthLineX)) {
            matrix[forthLineY][forthLineX].piece->Threatened = true;
            break;
        }

        if (!isEmpty(forthLineY, forthLineX)) {
            break;
        }

        matrix[forthLineY][forthLineX].movable = true;

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
        if (hasEnemyPiece(firstDiagonalY, firstDiagonalX)) {
            matrix[firstDiagonalY][firstDiagonalX].piece->Threatened = true;
            break;
        }

        if (!isEmpty(firstDiagonalY, firstDiagonalX)) {
            break;
        }

        matrix[firstDiagonalY][firstDiagonalX].movable = true;

        firstDiagonalX--;
        firstDiagonalY--;
    }

    // SECOND DIAGONAL

    while (secondDiagonalX <= 7 && secondDiagonalY >= 0) {
        if (hasEnemyPiece(secondDiagonalY, secondDiagonalX)) {
            matrix[secondDiagonalY][secondDiagonalX].piece->Threatened = true;
            break;
        }

        if (!isEmpty(secondDiagonalY, secondDiagonalX)) {
            break;
        }

        matrix[secondDiagonalY][secondDiagonalX].movable = true;

        secondDiagonalX++;
        secondDiagonalY--;
    }

    // THIRD DIAGONAL

    while (thirdDiagonalX <= 7 && thirdDiagonalY <= 7) {
        if (hasEnemyPiece(thirdDiagonalY, thirdDiagonalX)) {
            matrix[thirdDiagonalY][thirdDiagonalX].piece->Threatened = true;
            break;
        }

        if (!isEmpty(thirdDiagonalY, thirdDiagonalX)) {
            break;
        }

        matrix[thirdDiagonalY][thirdDiagonalX].movable = true;

        thirdDiagonalX++;
        thirdDiagonalY++;
    }

    // FORTH DIAGONAL
    
    while (forthDiagonalX >= 0 && forthDiagonalY <= 7) {
        if (hasEnemyPiece(forthDiagonalY, forthDiagonalX)) {
            matrix[forthDiagonalY][forthDiagonalX].piece->Threatened = true;
            break;
        }

        if (!isEmpty(forthDiagonalY, forthDiagonalX)) {
            break;
        }

        matrix[forthDiagonalY][forthDiagonalX].movable = true;

        forthDiagonalX--;
        forthDiagonalY++;
    }
}
