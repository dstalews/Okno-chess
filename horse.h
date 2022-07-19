#ifndef HORSE_H
#define HORSE_H
#include "piece.h"

class Horse: public Piece
{
public:
    Horse(int pieceColor);
    int validate(int row, int col, int checker);
};

#endif // HORSE_H
