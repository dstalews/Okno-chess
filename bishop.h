#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

class Bishop: public Piece
{
public:
    Bishop(int pieceColor);
    int validate(int row, int col, int checker);
};

#endif // BISHOP_H
