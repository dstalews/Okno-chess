#include "bishop.h"
#include "game.h"

extern Game *chess;

Bishop::Bishop(int pieceColor)
{
    this->pieceColor = pieceColor;
    this->pieceName = 'B';
    if (pieceColor)
        this->image_path = ":/Images/bishop_white.svg";
    else
        this->image_path = ":/Images/bishop_black.svg";
}

int Bishop::validate(Tile *temp, int checker)
{
    int r,c;
    int retVal=0, wcheck = 0;
    Tile *tmp = new Tile();

    r=temp->row;
    c=temp->col;
    while(r-->0 && c++<7)
    {
        if(!chess->tile[r][c]->piece)
        {
            if(checker)
            {
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c]);
                if (temp->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[temp->row][temp->col]);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
        }

        else if(chess->tile[r][c]->pieceColor==temp->pieceColor)
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }


        else if(chess->tile[r][c]->pieceColor!=temp->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r][c]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c]);
                if (temp->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[temp->row][temp->col]);
                chess->tile[r][c]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r-->0 && c-->0)
    {
        if(!chess->tile[r][c]->piece)
        {
            if(checker)
            {
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c]);
                if (temp->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[temp->row][temp->col]);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
        }

        else if(chess->tile[r][c]->pieceColor==temp->pieceColor)
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }

        else if(chess->tile[r][c]->pieceColor!=temp->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r][c]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c]);
                if (temp->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[temp->row][temp->col]);
                chess->tile[r][c]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7 && c++<7)
    {
        if(!chess->tile[r][c]->piece)
        {
            if(checker)
            {
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c]);
                if (temp->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[temp->row][temp->col]);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
        }

        else if(chess->tile[r][c]->pieceColor==temp->pieceColor)
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }

        else if(chess->tile[r][c]->pieceColor!=temp->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r][c]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c]);
                if (temp->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[temp->row][temp->col]);
                chess->tile[r][c]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7 && c-->0)
    {
        if(!chess->tile[r][c]->piece)
        {
            if(checker)
            {
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c]);
                if (temp->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[temp->row][temp->col]);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
        }

        else if(chess->tile[r][c]->pieceColor==temp->pieceColor)
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }

        else if(chess->tile[r][c]->pieceColor!=temp->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r][c]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c]);
                if (temp->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[temp->row][temp->col]);
                chess->tile[r][c]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }
    }

    delete tmp;
    return retVal;
}
