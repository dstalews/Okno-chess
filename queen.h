#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
#include "tile.h"

class Queen: public Piece
{
public:
    Queen(int pieceColor);
    int validate(Tile *temp, int checker);
};

#endif // QUEEN_H
