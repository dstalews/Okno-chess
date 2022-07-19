#ifndef PIECE_H
#define PIECE_H
#include <string>

class Piece
{
public:
    int pieceColor, en=0;
    char pieceName;
    std::string image_path;
    Piece();
    virtual int validate(int row, int col, int checker) {return 0;};
};

#endif // PIECE_H
