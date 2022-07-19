#ifndef HORSE_H
#define HORSE_H
#include "piece.h"
#include "tile.h"

class Horse: public Piece
{
public:
    Horse(int pieceColor);
    int validate(Tile *temp, int checker);
};

#endif // HORSE_H
