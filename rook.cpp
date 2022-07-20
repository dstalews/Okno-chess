#include "rook.h"
#include "game.h"

extern Game *chess;

Rook::Rook(int pieceColor)
{
    this->pieceColor = pieceColor;
    this->pieceName = 'R';
    if (pieceColor)
        this->imagePath = ":/Images/rook_white.svg";
    else
        this->imagePath = ":/Images/rook_black.svg";
}

int Rook::validate(int row, int col, int checker)
{
    int r,c;

    int retVal=0, wcheck = 0;
    Tile *tmp = new Tile();

    r=row;
    c=col;
    while(r-->0)
    {
        if(!chess->getTile(r,c)->pieceObject)
        {
            if(checker)
            {
                chess->getTile(row,col)->tileSwap(chess->getTile(r,c));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->row,chess->getWhiteKing()->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->row,chess->getBlackKing()->col,this->pieceColor);
                chess->getTile(r,c)->tileSwap(chess->getTile(row,col));
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r,c)->tileNum);
                retVal=1;
            }
        }

        else if(chess->getTile(r,c)->pieceObject->getPieceColor()==this->pieceColor)
        {
            if (!checker)
            {
                chess->newExp(chess->getTile(r,c)->tileNum);
                retVal=1;
            }
            break;
        }

        else if(chess->getTile(r,c)->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->getTile(r,c));
                chess->getTile(row,col)->tileSwap(chess->getTile(r,c));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->row,chess->getWhiteKing()->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->row,chess->getBlackKing()->col,this->pieceColor);
                chess->getTile(r,c)->tileSwap(chess->getTile(row,col));
                chess->getTile(r,c)->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r,c)->tileNum);
                retVal=1;
            }
            break;
        }
    }

    r=row;
    c=col;
    while(r++<7)
    {
        if(!chess->getTile(r,c)->pieceObject)
        {
            if(checker)
            {
                chess->getTile(row,col)->tileSwap(chess->getTile(r,c));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->row,chess->getWhiteKing()->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->row,chess->getBlackKing()->col,this->pieceColor);
                chess->getTile(r,c)->tileSwap(chess->getTile(row,col));
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r,c)->tileNum);
                retVal=1;
            }
        }

        else if(chess->getTile(r,c)->pieceObject->getPieceColor()==this->pieceColor)
        {
            if (!checker)
            {
                chess->newExp(chess->getTile(r,c)->tileNum);
                retVal=1;
            }
            break;
        }

        else if(chess->getTile(r,c)->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->getTile(r,c));
                chess->getTile(row,col)->tileSwap(chess->getTile(r,c));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->row,chess->getWhiteKing()->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->row,chess->getBlackKing()->col,this->pieceColor);
                chess->getTile(r,c)->tileSwap(chess->getTile(row,col));
                chess->getTile(r,c)->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r,c)->tileNum);
                retVal=1;
            }
            break;
        }
    }

    r=row;
    c=col;
    while(c++<7)
    {
        if(!chess->getTile(r,c)->pieceObject)
        {
            if(checker)
            {
                chess->getTile(row,col)->tileSwap(chess->getTile(r,c));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->row,chess->getWhiteKing()->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->row,chess->getBlackKing()->col,this->pieceColor);
                chess->getTile(r,c)->tileSwap(chess->getTile(row,col));
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r,c)->tileNum);
                retVal=1;
            }
        }

        else if(chess->getTile(r,c)->pieceObject->getPieceColor()==this->pieceColor)
        {
            if (!checker)
            {
                chess->newExp(chess->getTile(r,c)->tileNum);
                retVal=1;
            }
            break;
        }

        else if(chess->getTile(r,c)->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->getTile(r,c));
                chess->getTile(row,col)->tileSwap(chess->getTile(r,c));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->row,chess->getWhiteKing()->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->row,chess->getBlackKing()->col,this->pieceColor);
                chess->getTile(r,c)->tileSwap(chess->getTile(row,col));
                chess->getTile(r,c)->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r,c)->tileNum);
                retVal=1;
            }
            break;
        }
    }

    r=row;
    c=col;
    while(c-->0)
    {
        if(!chess->getTile(r,c)->pieceObject)
        {
            if(checker)
            {
                chess->getTile(row,col)->tileSwap(chess->getTile(r,c));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->row,chess->getWhiteKing()->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->row,chess->getBlackKing()->col,this->pieceColor);
                chess->getTile(r,c)->tileSwap(chess->getTile(row,col));
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r,c)->tileNum);
                retVal=1;
            }
        }

        else if(chess->getTile(r,c)->pieceObject->getPieceColor()==this->pieceColor)
        {
            if (!checker)
            {
                chess->newExp(chess->getTile(r,c)->tileNum);
                retVal=1;
            }
            break;
        }

        else if(chess->getTile(r,c)->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->getTile(r,c));
                chess->getTile(row,col)->tileSwap(chess->getTile(r,c));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->row,chess->getWhiteKing()->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->row,chess->getBlackKing()->col,this->pieceColor);
                chess->getTile(r,c)->tileSwap(chess->getTile(row,col));
                chess->getTile(r,c)->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r,c)->tileNum);
                retVal=1;
            }
            break;
        }
    }

    delete tmp;
    return retVal;
}
