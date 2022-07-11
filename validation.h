#ifndef VALIDATION_H
#define VALIDATION_H
#include "tile.h"

class Validation
{
public:
    Validation();
    int chooser(Tile *temp, int checker);
    int check(int r,int c, int color);
private:
    int validateBishop(Tile *temp, int checker);
    int validateQueen(Tile *temp, int checker);
    int validateKing(Tile *temp, int checker);
    int validateHorse(Tile *temp, int checker);
    int validateRook(Tile *temp, int checker);
    int validatePawn(Tile *temp, int checker);
};

#endif // VALIDATION_H
