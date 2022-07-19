#ifndef KING_H
#define KING_H
#include "piece.h"
#include "tile.h"

class King: public Piece
{
public:
    King(int pieceColor);
    int validate(Tile *temp, int checker);
};

#endif // KING_H
