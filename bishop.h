#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
#include "tile.h"

class Bishop: public Piece
{
public:
    Bishop(int pieceColor);
    int validate(Tile *temp, int checker);
};

#endif // BISHOP_H
