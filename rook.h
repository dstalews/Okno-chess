#ifndef ROOK_H
#define ROOK_H
#include "piece.h"

class Rook: public Piece
{
public:
    Rook(int pieceColor);
    int validate(int row, int col, int checker);
};

#endif // ROOK_H
