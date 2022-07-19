#ifndef PAWN_H
#define PAWN_H
#include "piece.h"

class Pawn: public Piece
{
public:
    Pawn(int pieceColor);
    int validate(int row, int col, int checker);
};

#endif // PAWN_H
