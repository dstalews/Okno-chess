#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <tile.h>

class Piece
{
public:
    int pieceColor, en=0;
    char pieceName;
    std::string image_path;
    Piece();
    virtual int validate(Tile *temp, int checker) {return 0;};
};

#endif // PIECE_H
