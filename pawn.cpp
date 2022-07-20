#include "pawn.h"
#include "game.h"

extern Game *chess;

Pawn::Pawn(int pieceColor)
{
    this->pieceColor = pieceColor;
    this->pieceName = 'P';
    if (pieceColor)
        this->imagePath = ":/Images/pawn_white.svg";
    else
        this->imagePath = ":/Images/pawn_black.svg";
}

int Pawn::validate(int row, int col, int checker)
{
    int retVal=0, wcheck = 0;
    Tile *tmp = new Tile();
    Piece *tmpPiece;

    //White Pawn
    if(this->pieceColor)
    {
        if(row-1>=0 && !chess->getTile(row-1,col)->getPieceObject() && checker)
        {

            chess->getTile(row,col)->tileSwap(chess->getTile(row-1,col));
            wcheck = chess->check(chess->getWhiteKing()->getRow(),chess->getWhiteKing()->getCol(),this->pieceColor);
            chess->getTile(row-1,col)->tileSwap(chess->getTile(row,col));

            if (!wcheck)
            {
                chess->newExp(chess->getTile(row-1,col)->getTileNum());
                retVal=1;
            }
        }

        if(row==6 && !chess->getTile(5,col)->getPieceObject() && !chess->getTile(4,col)->getPieceObject() && checker)
        {

            chess->getTile(row,col)->tileSwap(chess->getTile(row-2,col));
            wcheck = chess->check(chess->getWhiteKing()->getRow(),chess->getWhiteKing()->getCol(),this->pieceColor);
            chess->getTile(row-2,col)->tileSwap(chess->getTile(row,col));

            if (!wcheck)
            {
                chess->newExp(chess->getTile(row-2,col)->getTileNum());
                retVal=1;
            }
        }

        if(row-1>=0 && col-1>=0)
        {
            if(chess->getTile(row-1,col-1)->getPieceObject() && chess->getTile(row-1,col-1)->getPieceObject()->getPieceColor()!=this->pieceColor)
            {
                if(checker)
                {
                    tmp->tileCopy(chess->getTile(row-1,col-1));
                    chess->getTile(row,col)->tileSwap(chess->getTile(row-1,col-1));
                    wcheck = chess->check(chess->getWhiteKing()->getRow(),chess->getWhiteKing()->getCol(),this->pieceColor);
                    chess->getTile(row-1,col-1)->tileSwap(chess->getTile(row,col));
                    chess->getTile(row-1,col-1)->tileCopy(tmp);
                }

                if (!wcheck)
                {
                    chess->newExp(chess->getTile(row-1,col-1)->getTileNum());
                    retVal=1;
                }
            }
            else
            {
                if(!checker)
                {
                    chess->newExp(chess->getTile(row-1,col-1)->getTileNum());
                    retVal=1;
                }
            }
        }

        if(row-1>=0 && col+1<=7)
        {
            if(chess->getTile(row-1,col+1)->getPieceObject() && chess->getTile(row-1,col+1)->getPieceObject()->getPieceColor()!=this->pieceColor)
            {

                if(checker)
                {
                    tmp->tileCopy(chess->getTile(row-1,col+1));
                    chess->getTile(row,col)->tileSwap(chess->getTile(row-1,col+1));
                    wcheck = chess->check(chess->getWhiteKing()->getRow(),chess->getWhiteKing()->getCol(),this->pieceColor);
                    chess->getTile(row-1,col+1)->tileSwap(chess->getTile(row,col));
                    chess->getTile(row-1,col+1)->tileCopy(tmp);
                }

                if (!wcheck)
                {
                    chess->newExp(chess->getTile(row-1,col+1)->getTileNum());
                    retVal=1;
                }
            }
            else
            {
                if(!checker)
                {
                    chess->newExp(chess->getTile(row-1,col+1)->getTileNum());
                    retVal=1;
                }
            }
        }
        if(row==3 && col+1<=7 && checker)
        {
            if(chess->getTile(row,col+1)->getPieceObject() && chess->getTile(row,col+1)->getPieceObject()->getPieceColor()!=this->pieceColor && chess->getTile(row,col+1)->getPieceObject()->getPieceName()=='P' && chess->getTile(row,col+1)->getPieceObject()->getPieceEn()+1==chess->getTurnAll())
            {

                chess->getTile(row,col)->tileSwap(chess->getTile(row-1,col+1));
                tmpPiece = chess->getTile(row,col+1)->getPieceObject();
                chess->getTile(row,col+1)->setPieceObject(nullptr);
                wcheck = chess->check(chess->getWhiteKing()->getRow(),chess->getWhiteKing()->getCol(),this->pieceColor);
                chess->getTile(row-1,col+1)->tileSwap(chess->getTile(row,col));
                chess->getTile(row,col+1)->setPieceObject(tmpPiece);

                if (!wcheck)
                {
                    chess->newExp(chess->getTile(row-1,col+1)->getTileNum());
                    retVal=1;
                }
            }
        }

        if(row==3 && col-1>=0 && checker)
        {
            if(chess->getTile(row,col-1)->getPieceObject() && chess->getTile(row,col-1)->getPieceObject()->getPieceColor()!=this->pieceColor && chess->getTile(row,col-1)->getPieceObject()->getPieceName()=='P' && chess->getTile(row,col-1)->getPieceObject()->getPieceEn()+1==chess->getTurnAll())
            {
                chess->getTile(row,col)->tileSwap(chess->getTile(row-1,col-1));
                tmpPiece = chess->getTile(row,col-1)->getPieceObject();
                chess->getTile(row,col-1)->setPieceObject(nullptr);
                wcheck = chess->check(chess->getWhiteKing()->getRow(),chess->getWhiteKing()->getCol(),this->pieceColor);
                chess->getTile(row-1,col-1)->tileSwap(chess->getTile(row,col));
                chess->getTile(row,col-1)->setPieceObject(tmpPiece);

                if (!wcheck)
                {
                    chess->newExp(chess->getTile(row-1,col-1)->getTileNum());
                    retVal=1;
                }
            }
        }
    }
    else
    {
        if(row+1<=7 && !chess->getTile(row+1,col)->getPieceObject()  && checker)
        {
            chess->getTile(row,col)->tileSwap(chess->getTile(row+1,col));
            wcheck = chess->check(chess->getBlackKing()->getRow(),chess->getBlackKing()->getCol(),this->pieceColor);
            chess->getTile(row+1,col)->tileSwap(chess->getTile(row,col));

            if (!wcheck)
            {
                chess->newExp(chess->getTile(row+1,col)->getTileNum());
                retVal=1;
            }
        }

        if(row==1 && !chess->getTile(2,col)->getPieceObject() && !chess->getTile(3,col)->getPieceObject()  && checker)
        {
            chess->getTile(row,col)->tileSwap(chess->getTile(row+2,col));
            wcheck = chess->check(chess->getBlackKing()->getRow(),chess->getBlackKing()->getCol(),this->pieceColor);
            chess->getTile(row+2,col)->tileSwap(chess->getTile(row,col));

            if (!wcheck)
            {
                chess->newExp(chess->getTile(row+2,col)->getTileNum());
                retVal=1;
            }
        }

        if(row+1<=7 && col-1>=0)
        {
            if(chess->getTile(row+1,col-1)->getPieceObject() && chess->getTile(row+1,col-1)->getPieceObject()->getPieceColor()!=this->pieceColor)
            {
                if(checker)
                {
                    tmp->tileCopy(chess->getTile(row+1,col-1));
                    chess->getTile(row,col)->tileSwap(chess->getTile(row+1,col-1));
                    wcheck = chess->check(chess->getBlackKing()->getRow(),chess->getBlackKing()->getCol(),this->pieceColor);
                    chess->getTile(row+1,col-1)->tileSwap(chess->getTile(row,col));
                    chess->getTile(row+1,col-1)->tileCopy(tmp);
                }

                if (!wcheck)
                {
                    chess->newExp(chess->getTile(row+1,col-1)->getTileNum());
                    retVal=1;
                }
            }
            else
            {
                if(!checker)
                {
                    chess->newExp(chess->getTile(row+1,col-1)->getTileNum());
                    retVal=1;
                }
            }
        }

        if(row+1<=7 && col+1<=7)
        {
            if(chess->getTile(row+1,col+1)->getPieceObject() && chess->getTile(row+1,col+1)->getPieceObject()->getPieceColor()!=this->pieceColor)
            {
                if(checker)
                {
                    tmp->tileCopy(chess->getTile(row+1,col+1));
                    chess->getTile(row,col)->tileSwap(chess->getTile(row+1,col+1));
                    wcheck = chess->check(chess->getBlackKing()->getRow(),chess->getBlackKing()->getCol(),this->pieceColor);
                    chess->getTile(row+1,col+1)->tileSwap(chess->getTile(row,col));
                    chess->getTile(row+1,col+1)->tileCopy(tmp);
                }

                if (!wcheck)
                {
                    chess->newExp(chess->getTile(row+1,col+1)->getTileNum());
                    retVal=1;
                }
            }
            else
            {
                if(!checker)
                {
                    chess->newExp(chess->getTile(row+1,col+1)->getTileNum());
                    retVal=1;
                }
            }
        }

        if(row==4 && col+1<=7  && checker)
        {
            if(chess->getTile(row,col+1)->getPieceObject() && chess->getTile(row,col+1)->getPieceObject()->getPieceColor()!=this->pieceColor && chess->getTile(row,col+1)->getPieceObject()->getPieceName()=='P' && chess->getTile(row,col+1)->getPieceObject()->getPieceEn()+1==chess->getTurnAll())
            {
                chess->getTile(row,col)->tileSwap(chess->getTile(row+1,col+1));
                tmpPiece = chess->getTile(row,col+1)->getPieceObject();
                chess->getTile(row,col+1)->setPieceObject(nullptr);
                wcheck = chess->check(chess->getBlackKing()->getRow(),chess->getBlackKing()->getCol(),this->pieceColor);
                chess->getTile(row+1,col+1)->tileSwap(chess->getTile(row,col));
                chess->getTile(row,col+1)->setPieceObject(tmpPiece);

                if (!wcheck)
                {
                    chess->newExp(chess->getTile(row+1,col+1)->getTileNum());
                    retVal=1;
                }
            }
        }

        if(row==4 && col-1>=0  && checker)
        {
            if(chess->getTile(row,col-1)->getPieceObject() && chess->getTile(row,col-1)->getPieceObject()->getPieceColor()!=this->pieceColor && chess->getTile(row,col-1)->getPieceObject()->getPieceName()=='P' && chess->getTile(row,col-1)->getPieceObject()->getPieceEn()+1==chess->getTurnAll())
            {
                chess->getTile(row,col)->tileSwap(chess->getTile(row+1,col-1));
                tmpPiece = chess->getTile(row,col-1)->getPieceObject();
                chess->getTile(row,col-1)->setPieceObject(nullptr);
                wcheck = chess->check(chess->getBlackKing()->getRow(),chess->getBlackKing()->getCol(),this->pieceColor);
                chess->getTile(row+1,col-1)->tileSwap(chess->getTile(row,col));
                chess->getTile(row,col-1)->setPieceObject(tmpPiece);

                if (!wcheck)
                {
                    chess->newExp(chess->getTile(row+1,col-1)->getTileNum());
                    retVal=1;
                }
            }
        }
    }
    delete tmp;
    return retVal;
}
