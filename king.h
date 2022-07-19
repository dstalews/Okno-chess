#ifndef KING_H
#define KING_H
#include "piece.h"

class King: public Piece
{
public:
    King(int pieceColor);
    int validate(int row, int col, int checker);
};

#endif // KING_H
