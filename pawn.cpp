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
        if(row-1>=0 && !chess->tile[row-1][col]->pieceObject && checker)
        {

            chess->tile[row][col]->tileSwap(chess->tile[row-1][col]);
            wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
            chess->tile[row-1][col]->tileSwap(chess->tile[row][col]);

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[row-1][col]->tileNum;
                retVal=1;
            }
        }

        if(row==6 && !chess->tile[5][col]->pieceObject && !chess->tile[4][col]->pieceObject && checker)
        {

            chess->tile[row][col]->tileSwap(chess->tile[row-2][col]);
            wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
            chess->tile[row-2][col]->tileSwap(chess->tile[row][col]);

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[row-2][col]->tileNum;
                retVal=1;
            }
        }

        if(row-1>=0 && col-1>=0)
        {
            if(chess->tile[row-1][col-1]->pieceObject && chess->tile[row-1][col-1]->pieceObject->getPieceColor()!=this->pieceColor)
            {
                if(checker)
                {
                    tmp->tileCopy(chess->tile[row-1][col-1]);
                    chess->tile[row][col]->tileSwap(chess->tile[row-1][col-1]);
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                    chess->tile[row-1][col-1]->tileSwap(chess->tile[row][col]);
                    chess->tile[row-1][col-1]->tileCopy(tmp);
                }

                if (!wcheck)
                {
                    chess->exp[chess->max++]=chess->tile[row-1][col-1]->tileNum;
                    retVal=1;
                }
            }
            else
            {
                if(!checker)
                {
                    chess->exp[chess->max++]=chess->tile[row-1][col-1]->tileNum;
                    retVal=1;
                }
            }
        }

        if(row-1>=0 && col+1<=7)
        {
            if(chess->tile[row-1][col+1]->pieceObject && chess->tile[row-1][col+1]->pieceObject->getPieceColor()!=this->pieceColor)
            {

                if(checker)
                {
                    tmp->tileCopy(chess->tile[row-1][col+1]);
                    chess->tile[row][col]->tileSwap(chess->tile[row-1][col+1]);
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                    chess->tile[row-1][col+1]->tileSwap(chess->tile[row][col]);
                    chess->tile[row-1][col+1]->tileCopy(tmp);
                }

                if (!wcheck)
                {
                    chess->exp[chess->max++]=chess->tile[row-1][col+1]->tileNum;
                    retVal=1;
                }
            }
            else
            {
                if(!checker)
                {
                    chess->exp[chess->max++]=chess->tile[row-1][col+1]->tileNum;
                    retVal=1;
                }
            }
        }
        if(row==3 && col+1<=7 && checker)
        {
            if(chess->tile[row][col+1]->pieceObject && chess->tile[row][col+1]->pieceObject->getPieceColor()!=this->pieceColor && chess->tile[row][col+1]->pieceObject->getPieceName()=='P' && chess->tile[row][col+1]->pieceObject->getPieceEn()+1==chess->turnAll)
            {

                chess->tile[row][col]->tileSwap(chess->tile[row-1][col+1]);
                tmpPiece = chess->tile[row][col+1]->pieceObject;
                chess->tile[row][col+1]->pieceObject=nullptr;
                wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                chess->tile[row-1][col+1]->tileSwap(chess->tile[row][col]);
                chess->tile[row][col+1]->pieceObject=tmpPiece;

                if (!wcheck)
                {
                    chess->exp[chess->max++]=chess->tile[row-1][col+1]->tileNum;
                    retVal=1;
                }
            }
        }

        if(row==3 && col-1>=0 && checker)
        {
            if(chess->tile[row][col-1]->pieceObject && chess->tile[row][col-1]->pieceObject->getPieceColor()!=this->pieceColor && chess->tile[row][col-1]->pieceObject->getPieceName()=='P' && chess->tile[row][col-1]->pieceObject->getPieceEn()+1==chess->turnAll)
            {
                chess->tile[row][col]->tileSwap(chess->tile[row-1][col-1]);
                tmpPiece = chess->tile[row][col-1]->pieceObject;
                chess->tile[row][col-1]->pieceObject=nullptr;
                wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                chess->tile[row-1][col-1]->tileSwap(chess->tile[row][col]);
                chess->tile[row][col-1]->pieceObject=tmpPiece;

                if (!wcheck)
                {
                    chess->exp[chess->max++]=chess->tile[row-1][col-1]->tileNum;
                    retVal=1;
                }
            }
        }
    }
    else
    {
        if(row+1<=7 && !chess->tile[row+1][col]->pieceObject  && checker)
        {
            chess->tile[row][col]->tileSwap(chess->tile[row+1][col]);
            wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
            chess->tile[row+1][col]->tileSwap(chess->tile[row][col]);

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[row+1][col]->tileNum;
                retVal=1;
            }
        }

        if(row==1 && !chess->tile[2][col]->pieceObject && !chess->tile[3][col]->pieceObject  && checker)
        {
            chess->tile[row][col]->tileSwap(chess->tile[row+2][col]);
            wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
            chess->tile[row+2][col]->tileSwap(chess->tile[row][col]);

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[row+2][col]->tileNum;
                retVal=1;
            }
        }

        if(row+1<=7 && col-1>=0)
        {
            if(chess->tile[row+1][col-1]->pieceObject && chess->tile[row+1][col-1]->pieceObject->getPieceColor()!=this->pieceColor)
            {
                if(checker)
                {
                    tmp->tileCopy(chess->tile[row+1][col-1]);
                    chess->tile[row][col]->tileSwap(chess->tile[row+1][col-1]);
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                    chess->tile[row+1][col-1]->tileSwap(chess->tile[row][col]);
                    chess->tile[row+1][col-1]->tileCopy(tmp);
                }

                if (!wcheck)
                {
                    chess->exp[chess->max++]=chess->tile[row+1][col-1]->tileNum;
                    retVal=1;
                }
            }
            else
            {
                if(!checker)
                {
                    chess->exp[chess->max++]=chess->tile[row+1][col-1]->tileNum;
                    retVal=1;
                }
            }
        }

        if(row+1<=7 && col+1<=7)
        {
            if(chess->tile[row+1][col+1]->pieceObject && chess->tile[row+1][col+1]->pieceObject->getPieceColor()!=this->pieceColor)
            {
                if(checker)
                {
                    tmp->tileCopy(chess->tile[row+1][col+1]);
                    chess->tile[row][col]->tileSwap(chess->tile[row+1][col+1]);
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                    chess->tile[row+1][col+1]->tileSwap(chess->tile[row][col]);
                    chess->tile[row+1][col+1]->tileCopy(tmp);
                }

                if (!wcheck)
                {
                    chess->exp[chess->max++]=chess->tile[row+1][col+1]->tileNum;
                    retVal=1;
                }
            }
            else
            {
                if(!checker)
                {
                    chess->exp[chess->max++]=chess->tile[row+1][col+1]->tileNum;
                    retVal=1;
                }
            }
        }

        if(row==4 && col+1<=7  && checker)
        {
            if(chess->tile[row][col+1]->pieceObject && chess->tile[row][col+1]->pieceObject->getPieceColor()!=this->pieceColor && chess->tile[row][col+1]->pieceObject->getPieceName()=='P' && chess->tile[row][col+1]->pieceObject->getPieceEn()+1==chess->turnAll)
            {
                chess->tile[row][col]->tileSwap(chess->tile[row+1][col+1]);
                tmpPiece = chess->tile[row][col+1]->pieceObject;
                chess->tile[row][col+1]->pieceObject=nullptr;
                wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[row+1][col+1]->tileSwap(chess->tile[row][col]);
                chess->tile[row][col+1]->pieceObject=tmpPiece;

                if (!wcheck)
                {
                    chess->exp[chess->max++]=chess->tile[row+1][col+1]->tileNum;
                    retVal=1;
                }
            }
        }

        if(row==4 && col-1>=0  && checker)
        {
            if(chess->tile[row][col-1]->pieceObject && chess->tile[row][col-1]->pieceObject->getPieceColor()!=this->pieceColor && chess->tile[row][col-1]->pieceObject->getPieceName()=='P' && chess->tile[row][col-1]->pieceObject->getPieceEn()+1==chess->turnAll)
            {
                chess->tile[row][col]->tileSwap(chess->tile[row+1][col-1]);
                tmpPiece = chess->tile[row][col-1]->pieceObject;
                chess->tile[row][col-1]->pieceObject=nullptr;
                wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[row+1][col-1]->tileSwap(chess->tile[row][col]);
                chess->tile[row][col-1]->pieceObject=tmpPiece;

                if (!wcheck)
                {
                    chess->exp[chess->max++]=chess->tile[row+1][col-1]->tileNum;
                    retVal=1;
                }
            }
        }
    }
    delete tmp;
    return retVal;
}
