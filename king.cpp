#include "king.h"
#include "game.h"

extern Game *chess;

King::King(int pieceColor)
{
    this->pieceColor = pieceColor;
    this->pieceName = 'K';
    if (pieceColor)
        this->imagePath = ":/Images/king_white.svg";
    else
        this->imagePath = ":/Images/king_black.svg";
}

int King::validate(int row, int col, int checker)
{
    int r,c;
    int retVal=0, wcheck = 0;
    Tile *tmp = new Tile();

    r=row;
    c=col;

    if(r-1>=0)
    {
        if(chess->tile[r-1][c]->pieceObject==nullptr || chess->tile[r-1][c]->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r-1][c]);
                chess->tile[row][col]->tileSwap(chess->tile[r-1][c]);
                wcheck = chess->check(r-1,c,this->pieceColor);
                chess->tile[r-1][c]->tileSwap(chess->tile[row][col]);
                chess->tile[r-1][c]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r-1][c]->tileNum;
                retVal=1;
            }
        }
    }

    if(r+1<=7)
    {
        if(chess->tile[r+1][c]->pieceObject==nullptr || chess->tile[r+1][c]->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r+1][c]);
                chess->tile[row][col]->tileSwap(chess->tile[r+1][c]);
                wcheck = chess->check(r+1,c,this->pieceColor);
                chess->tile[r+1][c]->tileSwap(chess->tile[row][col]);
                chess->tile[r+1][c]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r+1][c]->tileNum;
                retVal=1;
            }
        }
    }

    if(c-1>=0)
    {
        if(chess->tile[r][c-1]->pieceObject==nullptr || chess->tile[r][c-1]->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r][c-1]);
                chess->tile[row][col]->tileSwap(chess->tile[r][c-1]);
                wcheck = chess->check(r,c-1,this->pieceColor);
                chess->tile[r][c-1]->tileSwap(chess->tile[row][col]);
                chess->tile[r][c-1]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c-1]->tileNum;
                retVal=1;
            }
        }
    }

    if(c+1<=7)
    {
        if(chess->tile[r][c+1]->pieceObject==nullptr || chess->tile[r][c+1]->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r][c+1]);
                chess->tile[row][col]->tileSwap(chess->tile[r][c+1]);
                wcheck = chess->check(r,c+1,this->pieceColor);
                chess->tile[r][c+1]->tileSwap(chess->tile[row][col]);
                chess->tile[r][c+1]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c+1]->tileNum;
                retVal=1;
            }
        }
    }

    if(r-1>=0 && c-1>=0)
    {
        if(chess->tile[r-1][c-1]->pieceObject==nullptr || chess->tile[r-1][c-1]->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r-1][c-1]);
                chess->tile[row][col]->tileSwap(chess->tile[r-1][c-1]);
                wcheck = chess->check(r-1,c-1,this->pieceColor);
                chess->tile[r-1][c-1]->tileSwap(chess->tile[row][col]);
                chess->tile[r-1][c-1]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r-1][c-1]->tileNum;
                retVal=1;
            }
        }
    }

    if(r-1>=0 && c+1<=7)
    {
        if(chess->tile[r-1][c+1]->pieceObject==nullptr || chess->tile[r-1][c+1]->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r-1][c+1]);
                chess->tile[row][col]->tileSwap(chess->tile[r-1][c+1]);
                wcheck = chess->check(r-1,c+1,this->pieceColor);
                chess->tile[r-1][c+1]->tileSwap(chess->tile[row][col]);
                chess->tile[r-1][c+1]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r-1][c+1]->tileNum;
                retVal=1;
            }
        }
    }

    if(r+1<=7 && c-1>=0)
    {
        if(chess->tile[r+1][c-1]->pieceObject==nullptr || chess->tile[r+1][c-1]->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r+1][c-1]);
                chess->tile[row][col]->tileSwap(chess->tile[r+1][c-1]);
                wcheck = chess->check(r+1,c-1,this->pieceColor);
                chess->tile[r+1][c-1]->tileSwap(chess->tile[row][col]);
                chess->tile[r+1][c-1]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r+1][c-1]->tileNum;
                retVal=1;
            }
        }
    }

    if(r+1<=7 && c+1<=7)
    {
        if(chess->tile[r+1][c+1]->pieceObject==nullptr || chess->tile[r+1][c+1]->pieceObject->getPieceColor()!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r+1][c+1]);
                chess->tile[row][col]->tileSwap(chess->tile[r+1][c+1]);
                wcheck = chess->check(r+1,c+1,this->pieceColor);
                chess->tile[r+1][c+1]->tileSwap(chess->tile[row][col]);
                chess->tile[r+1][c+1]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r+1][c+1]->tileNum;
                retVal=1;
            }
        }
    }

    if(r==0 && c==4 && !this->pieceColor && !this->en && checker && !chess->check(r,c,this->pieceColor))
    {
        if(chess->tile[0][7]->pieceObject && !chess->tile[0][6]->pieceObject && !chess->tile[0][5]->pieceObject && chess->tile[0][7]->pieceObject->getPieceName() == 'R' &&
                !chess->check(0,6,this->pieceColor) && !chess->check(0,5,this->pieceColor) && !chess->tile[0][7]->pieceObject->getPieceColor() && !chess->tile[0][7]->pieceObject->getPieceEn())
        {
            chess->exp[chess->max++]=chess->tile[r][c+2]->tileNum;
            retVal=1;
        }
        if(chess->tile[0][0]->pieceObject && !chess->tile[0][3]->pieceObject && !chess->tile[0][2]->pieceObject && !chess->tile[0][1]->pieceObject && chess->tile[0][0]->pieceObject->getPieceName() == 'R' &&
                !chess->check(0,3,this->pieceColor) && !chess->check(0,2,this->pieceColor) && !chess->check(0,1,this->pieceColor) && !chess->tile[0][0]->pieceObject->getPieceColor() && !chess->tile[0][0]->pieceObject->getPieceEn())
        {
            chess->exp[chess->max++]=chess->tile[r][c-2]->tileNum;
            retVal=1;
        }
    }

    if(r==7 && c==4 && this->pieceColor && !this->en && !chess->check(r,c,this->pieceColor) && checker)
    {
        if(chess->tile[7][7]->pieceObject && !chess->tile[7][6]->pieceObject && !chess->tile[7][5]->pieceObject && chess->tile[7][7]->pieceObject->getPieceName() == 'R' &&
                !chess->check(7,6,this->pieceColor) && !chess->check(7,5,this->pieceColor) && chess->tile[7][7]->pieceObject->getPieceColor() && !chess->tile[7][7]->pieceObject->getPieceEn())
        {
            chess->exp[chess->max++]=chess->tile[r][c+2]->tileNum;
            retVal=1;
        }
        if(chess->tile[7][0]->pieceObject && !chess->tile[7][3]->pieceObject && !chess->tile[7][2]->pieceObject && !chess->tile[7][1]->pieceObject && chess->tile[7][0]->pieceObject->getPieceName() == 'R' &&
                !chess->check(7,3,this->pieceColor) && !chess->check(7,2,this->pieceColor) && !chess->check(7,1,this->pieceColor) && chess->tile[7][0]->pieceObject->getPieceColor() && !chess->tile[7][0]->pieceObject->getPieceEn())
        {
            chess->exp[chess->max++]=chess->tile[r][c-2]->tileNum;
            retVal=1;
        }
    }

    delete tmp;
    return retVal;
}

