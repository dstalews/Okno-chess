#include "bishop.h"
#include "game.h"

extern Game *chess;

Bishop::Bishop(int pieceColor)
{
    this->pieceColor = pieceColor;
    this->pieceName = 'B';
    if (pieceColor)
        this->imagePath = ":/Images/bishop_white.svg";
    else
        this->imagePath = ":/Images/bishop_black.svg";
}

int Bishop::validate(int row, int col, int checker)
{
    int r,c;
    int retVal=0, wcheck = 0;
    Tile *tmp = new Tile();

    r=row;
    c=col;
    while(r-->0 && c++<7)
    {
        if(!chess->getTile(r,c)->getPieceObject())
        {
            if(checker)
            {
                chess->getTile(row,col)->tileSwap(chess->getTile(r,c));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->getRow(),chess->getWhiteKing()->getCol(),this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->getRow(),chess->getBlackKing()->getCol(),this->pieceColor);
                chess->getTile(r,c)->tileSwap(chess->getTile(row,col));
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r,c)->getTileNum());
                retVal=1;
            }
        }

        else if(chess->getTile(r,c)->getPieceObject()->getPieceColor()==this->pieceColor)
        {
            if (!checker)
            {
                chess->newExp(chess->getTile(r,c)->getTileNum());
                retVal=1;
            }
            break;
        }


        else if(chess->getTile(r,c)->getPieceObject()->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->getTile(r,c));
                chess->getTile(row,col)->tileSwap(chess->getTile(r,c));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->getRow(),chess->getWhiteKing()->getCol(),this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->getRow(),chess->getBlackKing()->getCol(),this->pieceColor);
                chess->getTile(r,c)->tileSwap(chess->getTile(row,col));
                chess->getTile(r,c)->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r,c)->getTileNum());
                retVal=1;
            }
            break;
        }
    }

    r=row;
    c=col;
    while(r-->0 && c-->0)
    {
        if(!chess->getTile(r,c)->getPieceObject())
        {
            if(checker)
            {
                chess->getTile(row,col)->tileSwap(chess->getTile(r,c));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->getRow(),chess->getWhiteKing()->getCol(),this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->getRow(),chess->getBlackKing()->getCol(),this->pieceColor);
                chess->getTile(r,c)->tileSwap(chess->getTile(row,col));
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r,c)->getTileNum());
                retVal=1;
            }
        }

        else if(chess->getTile(r,c)->getPieceObject()->getPieceColor()==this->pieceColor)
        {
            if (!checker)
            {
                chess->newExp(chess->getTile(r,c)->getTileNum());
                retVal=1;
            }
            break;
        }

        else if(chess->getTile(r,c)->getPieceObject()->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->getTile(r,c));
                chess->getTile(row,col)->tileSwap(chess->getTile(r,c));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->getRow(),chess->getWhiteKing()->getCol(),this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->getRow(),chess->getBlackKing()->getCol(),this->pieceColor);
                chess->getTile(r,c)->tileSwap(chess->getTile(row,col));
                chess->getTile(r,c)->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r,c)->getTileNum());
                retVal=1;
            }
            break;
        }
    }

    r=row;
    c=col;
    while(r++<7 && c++<7)
    {
        if(!chess->getTile(r,c)->getPieceObject())
        {
            if(checker)
            {
                chess->getTile(row,col)->tileSwap(chess->getTile(r,c));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->getRow(),chess->getWhiteKing()->getCol(),this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->getRow(),chess->getBlackKing()->getCol(),this->pieceColor);
                chess->getTile(r,c)->tileSwap(chess->getTile(row,col));
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r,c)->getTileNum());
                retVal=1;
            }
        }

        else if(chess->getTile(r,c)->getPieceObject()->getPieceColor()==this->pieceColor)
        {
            if (!checker)
            {
                chess->newExp(chess->getTile(r,c)->getTileNum());
                retVal=1;
            }
            break;
        }

        else if(chess->getTile(r,c)->getPieceObject()->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->getTile(r,c));
                chess->getTile(row,col)->tileSwap(chess->getTile(r,c));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->getRow(),chess->getWhiteKing()->getCol(),this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->getRow(),chess->getBlackKing()->getCol(),this->pieceColor);
                chess->getTile(r,c)->tileSwap(chess->getTile(row,col));
                chess->getTile(r,c)->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r,c)->getTileNum());
                retVal=1;
            }
            break;
        }
    }

    r=row;
    c=col;
    while(r++<7 && c-->0)
    {
        if(!chess->getTile(r,c)->getPieceObject())
        {
            if(checker)
            {
                chess->getTile(row,col)->tileSwap(chess->getTile(r,c));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->getRow(),chess->getWhiteKing()->getCol(),this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->getRow(),chess->getBlackKing()->getCol(),this->pieceColor);
                chess->getTile(r,c)->tileSwap(chess->getTile(row,col));
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r,c)->getTileNum());
                retVal=1;
            }
        }

        else if(chess->getTile(r,c)->getPieceObject()->getPieceColor()==this->pieceColor)
        {
            if (!checker)
            {
                chess->newExp(chess->getTile(r,c)->getTileNum());
                retVal=1;
            }
            break;
        }

        else if(chess->getTile(r,c)->getPieceObject()->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->getTile(r,c));
                chess->getTile(row,col)->tileSwap(chess->getTile(r,c));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->getRow(),chess->getWhiteKing()->getCol(),this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->getRow(),chess->getBlackKing()->getCol(),this->pieceColor);
                chess->getTile(r,c)->tileSwap(chess->getTile(row,col));
                chess->getTile(r,c)->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r,c)->getTileNum());
                retVal=1;
            }
            break;
        }
    }

    delete tmp;
    return retVal;
}
