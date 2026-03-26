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

    auto hasEnemyPiece = [&](int row, int column) {
        return matrix[row][column].piece != nullptr && Color != matrix[row][column].piece->Color;
    };

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

// bool Bishop::check(Board matrix[][8]) {
//     bool check = false;

//     int firstDiagonalX = Column - 1;
//     int firstDiagonalY = Row - 1;

//     int secondDiagonalX = Column + 1;
//     int secondDiagonalY = Row - 1;

//     int thirdDiagonalX = Column + 1;
//     int thirdDiagonalY = Row + 1;

//     int forthDiagonalX = Column - 1;
//     int forthDiagonalY = Row + 1;

//     auto isEmpty = [&](int row, int column) {
//         return matrix[row][column].piece == nullptr;
//     };

//     auto hasKing = [&](int row, int column) {
//         return matrix[row][column].piece == KING && Color != matrix[row][column].piece->Color;
//     };

//     // FIRST DIAGONAL
    
//     while (firstDiagonalX >= 0 && firstDiagonalY >= 0) {
//         if (hasKing(firstDiagonalY, firstDiagonalX)) {
//             matrix[firstDiagonalY][firstDiagonalX].drawColor = checkColor;
//             check = true;
//             break;
//         }

//         if (!isEmpty(firstDiagonalY, firstDiagonalX)) {
//             break;
//         }

//         firstDiagonalX--;
//         firstDiagonalY--;
//     }

//     // SECOND DIAGONAL

//     while (secondDiagonalX <= 7 && secondDiagonalY >= 0) {
//         if (hasKing(secondDiagonalY, secondDiagonalX)) {
//             matrix[secondDiagonalY][secondDiagonalX].drawColor = checkColor;
//             check = true;
//             break;
//         }

//         if (!isEmpty(secondDiagonalY, secondDiagonalX)) {
//             break;
//         }

//         secondDiagonalX++;
//         secondDiagonalY--;
//     }

//     // THIRD DIAGONAL

//     while (thirdDiagonalX <= 7 && thirdDiagonalY <= 7) {
//         if (hasKing(thirdDiagonalY, thirdDiagonalX)) {
//             matrix[thirdDiagonalY][thirdDiagonalX].drawColor = checkColor;
//             check = true;
//             break;
//         }

//         if (!isEmpty(thirdDiagonalY, thirdDiagonalX)) {
//             break;
//         }

//         thirdDiagonalX++;
//         thirdDiagonalY++;
//     }

//     // FORTH DIAGONAL
    
//     while (forthDiagonalX >= 0 && forthDiagonalY <= 7) {
//         if (hasKing(forthDiagonalY, forthDiagonalX)) {
//             matrix[forthDiagonalY][forthDiagonalX].drawColor = checkColor;
//             check = true;
//             break;
//         }

//         if (!isEmpty(forthDiagonalY, forthDiagonalX)) {
//             break;
//         }

//         forthDiagonalX--;
//         forthDiagonalY++;
//     }

//     return check;
// }
