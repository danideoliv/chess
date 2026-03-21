#include <iostream>
#include "pieces.h"

Rook::Rook(int row, int column, int color) : Piece(row, column, color) {
    setType(ROOK);
    itMoved(false);
    setValue(5);
}

void Rook::possibleSquares(string matrix[][8], Board matrix2[][8]) {
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
}