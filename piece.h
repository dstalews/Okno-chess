#ifndef PIECE_H
#define PIECE_H
#include <string>

class Piece
{
protected:
    int pieceColor, en=0;
    char pieceName;
    std::string imagePath;
public:
    Piece();
    virtual int validate(int row, int col, int checker) {return row+col+checker;};
    char getPieceName();
    int getPieceColor();
    int getPieceEn();
    std::string getImagePath();
    void setEn(int i);
};

#endif // PIECE_H
