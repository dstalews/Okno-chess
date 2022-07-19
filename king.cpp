#include "king.h"
#include "game.h"

extern Game *chess;

King::King(int pieceColor)
{
    this->pieceColor = pieceColor;
    this->pieceName = 'K';
    if (pieceColor)
        this->image_path = ":/Images/king_white.svg";
    else
        this->image_path = ":/Images/king_black.svg";
}

int King::validate(Tile *temp, int checker)
{
    int r,c;
    int retVal=0, wcheck = 0;
    Tile *tmp = new Tile();

    r=temp->row;
    c=temp->col;

    if(r-1>=0)
    {
        if(!chess->tile[r-1][c]->piece || chess->tile[r-1][c]->pieceColor!=temp->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r-1][c]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r-1][c]);
                wcheck = chess->check(r-1,c,temp->pieceColor);
                chess->tile[r-1][c]->tileSwap(chess->tile[temp->row][temp->col]);
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
        if(!chess->tile[r+1][c]->piece || chess->tile[r+1][c]->pieceColor!=temp->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r+1][c]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r+1][c]);
                wcheck = chess->check(r+1,c,temp->pieceColor);
                chess->tile[r+1][c]->tileSwap(chess->tile[temp->row][temp->col]);
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
        if(!chess->tile[r][c-1]->piece || chess->tile[r][c-1]->pieceColor!=temp->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r][c-1]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c-1]);
                wcheck = chess->check(r,c-1,temp->pieceColor);
                chess->tile[r][c-1]->tileSwap(chess->tile[temp->row][temp->col]);
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
        if(!chess->tile[r][c+1]->piece || chess->tile[r][c+1]->pieceColor!=temp->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r][c+1]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c+1]);
                wcheck = chess->check(r,c+1,temp->pieceColor);
                chess->tile[r][c+1]->tileSwap(chess->tile[temp->row][temp->col]);
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
        if(!chess->tile[r-1][c-1]->piece || chess->tile[r-1][c-1]->pieceColor!=temp->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r-1][c-1]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r-1][c-1]);
                wcheck = chess->check(r-1,c-1,temp->pieceColor);
                chess->tile[r-1][c-1]->tileSwap(chess->tile[temp->row][temp->col]);
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
        if(!chess->tile[r-1][c+1]->piece || chess->tile[r-1][c+1]->pieceColor!=temp->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r-1][c+1]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r-1][c+1]);
                wcheck = chess->check(r-1,c+1,temp->pieceColor);
                chess->tile[r-1][c+1]->tileSwap(chess->tile[temp->row][temp->col]);
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
        if(!chess->tile[r+1][c-1]->piece || chess->tile[r+1][c-1]->pieceColor!=temp->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r+1][c-1]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r+1][c-1]);
                wcheck = chess->check(r+1,c-1,temp->pieceColor);
                chess->tile[r+1][c-1]->tileSwap(chess->tile[temp->row][temp->col]);
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
        if(!chess->tile[r+1][c+1]->piece || chess->tile[r+1][c+1]->pieceColor!=temp->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r+1][c+1]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r+1][c+1]);
                wcheck = chess->check(r+1,c+1,temp->pieceColor);
                chess->tile[r+1][c+1]->tileSwap(chess->tile[temp->row][temp->col]);
                chess->tile[r+1][c+1]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r+1][c+1]->tileNum;
                retVal=1;
            }
        }
    }

    if(r==0 && c==4 && !temp->pieceColor && !temp->en && checker && !chess->check(r,c,temp->pieceColor))
    {
        if(chess->tile[0][7]->piece && !chess->tile[0][6]->piece && !chess->tile[0][5]->piece && chess->tile[0][7]->pieceName == 'R' &&
                !chess->check(0,6,temp->pieceColor) && !chess->check(0,5,temp->pieceColor) && !chess->tile[0][7]->pieceColor && !chess->tile[0][7]->en)
        {
            chess->exp[chess->max++]=chess->tile[r][c+2]->tileNum;
            retVal=1;
        }
        if(chess->tile[0][0]->piece && !chess->tile[0][3]->piece && !chess->tile[0][2]->piece && !chess->tile[0][1]->piece && chess->tile[0][0]->pieceName == 'R' &&
                !chess->check(0,3,temp->pieceColor) && !chess->check(0,2,temp->pieceColor) && !chess->check(0,1,temp->pieceColor) && !chess->tile[0][0]->pieceColor && !chess->tile[0][0]->en)
        {
            chess->exp[chess->max++]=chess->tile[r][c-2]->tileNum;
            retVal=1;
        }
    }

    if(r==7 && c==4 && temp->pieceColor && !temp->en && !chess->check(r,c,temp->pieceColor) && checker)
    {
        if(chess->tile[7][7]->piece && !chess->tile[7][6]->piece && !chess->tile[7][5]->piece && chess->tile[7][7]->pieceName == 'R' &&
                !chess->check(7,6,temp->pieceColor) && !chess->check(7,5,temp->pieceColor) && chess->tile[7][7]->pieceColor && !chess->tile[7][7]->en)
        {
            chess->exp[chess->max++]=chess->tile[r][c+2]->tileNum;
            retVal=1;
        }
        if(chess->tile[7][0]->piece && !chess->tile[7][3]->piece && !chess->tile[7][2]->piece && !chess->tile[7][1]->piece && chess->tile[7][0]->pieceName == 'R' &&
                !chess->check(7,3,temp->pieceColor) && !chess->check(7,2,temp->pieceColor) && !chess->check(7,1,temp->pieceColor) && chess->tile[7][0]->pieceColor && !chess->tile[7][0]->en)
        {
            chess->exp[chess->max++]=chess->tile[r][c-2]->tileNum;
            retVal=1;
        }
    }

    delete tmp;
    return retVal;
}

