#include "piece.h"

Piece::Piece()
{
    //Nothing here
}


char Piece::getPieceName()
{
    return pieceName;
}

int Piece::getPieceColor()
{
    return pieceColor;
}

int Piece::getPieceEn()
{
    return en;
}

std::string Piece::getImagePath()
{
    return imagePath;
}

void Piece::setEn(int i)
{
    en = i;
}
