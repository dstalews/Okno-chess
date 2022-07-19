#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen: public Piece
{
public:
    Queen(int pieceColor);
    int validate(int row, int col, int checker);
};

#endif // QUEEN_H
