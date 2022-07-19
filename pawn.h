#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
#include "tile.h"

class Pawn: public Piece
{
public:
    Pawn(int pieceColor);
    int validate(Tile *temp, int checker);
};

#endif // PAWN_H
