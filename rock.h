#ifndef ROCK_H
#define ROCK_H
#include "piece.h"
#include "tile.h"

class Rock: public Piece
{
public:
    Rock(int pieceColor);
    int validate(Tile *temp, int checker);
};

#endif // ROCK_H
