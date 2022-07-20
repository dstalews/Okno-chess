#include "horse.h"
#include "game.h"

extern Game *chess;

Horse::Horse(int pieceColor)
{
    this->pieceColor = pieceColor;
    this->pieceName = 'H';
    if (pieceColor)
        this->imagePath = ":/Images/knight_white.svg";
    else
        this->imagePath = ":/Images/knight_black.svg";
}

int Horse::validate(int row, int col, int checker)
{
    int r,c;
    int retVal=0, wcheck = 0;
    Tile *tmp = new Tile();

    r=row;
    c=col;

    if(r-2>=0 && c-1>=0)
    {
        if(chess->getTile(r-2,c-1)->pieceObject==nullptr || chess->getTile(r-2,c-1)->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->getTile(r-2,c-1));
                chess->getTile(row,col)->tileSwap(chess->getTile(r-2,c-1));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->row,chess->getWhiteKing()->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->row,chess->getBlackKing()->col,this->pieceColor);
                chess->getTile(r-2,c-1)->tileSwap(chess->getTile(row,col));
                chess->getTile(r-2,c-1)->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r-2,c-1)->tileNum);
                retVal=1;
            }
        }
        else
        {
            if (!checker)
            {
                chess->newExp(chess->getTile(r-2,c-1)->tileNum);
                retVal=1;
            }
        }
    }

    if(r-2>=0 && c+1<=7)
    {
        if(chess->getTile(r-2,c+1)->pieceObject==nullptr||chess->getTile(r-2,c+1)->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->getTile(r-2,c+1));
                chess->getTile(row,col)->tileSwap(chess->getTile(r-2,c+1));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->row,chess->getWhiteKing()->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->row,chess->getBlackKing()->col,this->pieceColor);
                chess->getTile(r-2,c+1)->tileSwap(chess->getTile(row,col));
                chess->getTile(r-2,c+1)->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r-2,c+1)->tileNum);
                retVal=1;
            }
        }
        else
        {
            if (!checker)
            {
                chess->newExp(chess->getTile(r-2,c+1)->tileNum);
                retVal=1;
            }
        }
    }

    if(r-1>=0 && c-2>=0)
    {
        if(chess->getTile(r-1,c-2)->pieceObject==nullptr||chess->getTile(r-1,c-2)->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->getTile(r-1,c-2));
                chess->getTile(row,col)->tileSwap(chess->getTile(r-1,c-2));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->row,chess->getWhiteKing()->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->row,chess->getBlackKing()->col,this->pieceColor);
                chess->getTile(r-1,c-2)->tileSwap(chess->getTile(row,col));
                chess->getTile(r-1,c-2)->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r-1,c-2)->tileNum);
                retVal=1;
            }
        }
        else
        {
            if (!checker)
            {
                chess->newExp(chess->getTile(r-1,c-2)->tileNum);
                retVal=1;
            }
        }
    }

    if(r-1>=0 && c+2<=7)
    {
        if(chess->getTile(r-1,c+2)->pieceObject==nullptr || chess->getTile(r-1,c+2)->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->getTile(r-1,c+2));
                chess->getTile(row,col)->tileSwap(chess->getTile(r-1,c+2));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->row,chess->getWhiteKing()->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->row,chess->getBlackKing()->col,this->pieceColor);
                chess->getTile(r-1,c+2)->tileSwap(chess->getTile(row,col));
                chess->getTile(r-1,c+2)->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r-1,c+2)->tileNum);
                retVal=1;
            }
        }
        else
        {
            if (!checker)
            {
                chess->newExp(chess->getTile(r-1,c+2)->tileNum);
                retVal=1;
            }
        }
    }

    if(r+2<=7 && c+1<=7)
    {
        if(chess->getTile(r+2,c+1)->pieceObject == nullptr || chess->getTile(r+2,c+1)->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->getTile(r+2,c+1));
                chess->getTile(row,col)->tileSwap(chess->getTile(r+2,c+1));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->row,chess->getWhiteKing()->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->row,chess->getBlackKing()->col,this->pieceColor);
                chess->getTile(r+2,c+1)->tileSwap(chess->getTile(row,col));
                chess->getTile(r+2,c+1)->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r+2,c+1)->tileNum);
                retVal=1;
            }
        }
        else
        {
            if (!checker)
            {
                chess->newExp(chess->getTile(r+2,c+1)->tileNum);
                retVal=1;
            }
        }
    }

    if(r+2<=7 && c-1>=0)
    {
        if(chess->getTile(r+2,c-1)->pieceObject==nullptr || chess->getTile(r+2,c-1)->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->getTile(r+2,c-1));
                chess->getTile(row,col)->tileSwap(chess->getTile(r+2,c-1));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->row,chess->getWhiteKing()->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->row,chess->getBlackKing()->col,this->pieceColor);
                chess->getTile(r+2,c-1)->tileSwap(chess->getTile(row,col));
                chess->getTile(r+2,c-1)->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r+2,c-1)->tileNum);
                retVal=1;
            }
        }
        else
        {
            if (!checker)
            {
                chess->newExp(chess->getTile(r+2,c-1)->tileNum);
                retVal=1;
            }
        }
    }

    if(r+1<=7 && c-2>=0)
    {
        if(chess->getTile(r+1,c-2)->pieceObject==nullptr||chess->getTile(r+1,c-2)->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->getTile(r+1,c-2));
                chess->getTile(row,col)->tileSwap(chess->getTile(r+1,c-2));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->row,chess->getWhiteKing()->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->row,chess->getBlackKing()->col,this->pieceColor);
                chess->getTile(r+1,c-2)->tileSwap(chess->getTile(row,col));
                chess->getTile(r+1,c-2)->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r+1,c-2)->tileNum);
                retVal=1;
            }
        }
        else
        {
            if (!checker)
            {
                chess->newExp(chess->getTile(r+1,c-2)->tileNum);
                retVal=1;
            }
        }
    }

    if(r+1<=7 && c+2<=7)
    {
        if(chess->getTile(r+1,c+2)->pieceObject==nullptr||chess->getTile(r+1,c+2)->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->getTile(r+1,c+2));
                chess->getTile(row,col)->tileSwap(chess->getTile(r+1,c+2));
                if (this->pieceColor)
                    wcheck = chess->check(chess->getWhiteKing()->row,chess->getWhiteKing()->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->getBlackKing()->row,chess->getBlackKing()->col,this->pieceColor);
                chess->getTile(r+1,c+2)->tileSwap(chess->getTile(row,col));
                chess->getTile(r+1,c+2)->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->newExp(chess->getTile(r+1,c+2)->tileNum);
                retVal=1;
            }
        }
        else
        {
            if (!checker)
            {
                chess->newExp(chess->getTile(r+1,c+2)->tileNum);
                retVal=1;
            }
        }
    }

    delete tmp;
    return retVal;
}
