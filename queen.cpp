#include "queen.h"
#include "game.h"

extern Game *chess;

Queen::Queen(int pieceColor)
{
    this->pieceColor = pieceColor;
    this->pieceName = 'Q';
    if (pieceColor)
        this->image_path = ":/Images/queen_white.svg";
    else
        this->image_path = ":/Images/queen_black.svg";
}

int Queen::validate(int row, int col, int checker)
{
    int r,c;

    int retVal=0, wcheck = 0;
    Tile *tmp = new Tile();

    r=row;
    c=col;
    while(r-->0)
    {
        if(!chess->tile[r][c]->pieceObject)
        {
            if(checker)
            {
                chess->tile[row][col]->tileSwap(chess->tile[r][c]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[row][col]);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
        }

        else if(chess->tile[r][c]->pieceObject->pieceColor==this->pieceColor)
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }

        else if(chess->tile[r][c]->pieceObject->pieceColor!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r][c]);
                chess->tile[row][col]->tileSwap(chess->tile[r][c]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[row][col]);
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

    r=row;
    c=col;
    while(r++<7)
    {
        if(!chess->tile[r][c]->pieceObject)
        {
            if(checker)
            {
                chess->tile[row][col]->tileSwap(chess->tile[r][c]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[row][col]);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
        }

        else if(chess->tile[r][c]->pieceObject->pieceColor==this->pieceColor)
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }

        else if(chess->tile[r][c]->pieceObject->pieceColor!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r][c]);
                chess->tile[row][col]->tileSwap(chess->tile[r][c]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[row][col]);
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

    r=row;
    c=col;
    while(c++<7)
    {
        if(!chess->tile[r][c]->pieceObject)
        {
            if(checker)
            {
                chess->tile[row][col]->tileSwap(chess->tile[r][c]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[row][col]);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
        }

        else if(chess->tile[r][c]->pieceObject->pieceColor==this->pieceColor)
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }

        else if(chess->tile[r][c]->pieceObject->pieceColor!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r][c]);
                chess->tile[row][col]->tileSwap(chess->tile[r][c]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[row][col]);
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

    r=row;
    c=col;
    while(c-->0)
    {
        if(!chess->tile[r][c]->pieceObject)
        {
            if(checker)
            {
                chess->tile[row][col]->tileSwap(chess->tile[r][c]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[row][col]);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
        }

        else if(chess->tile[r][c]->pieceObject->pieceColor==this->pieceColor)
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }

        else if(chess->tile[r][c]->pieceObject->pieceColor!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r][c]);
                chess->tile[row][col]->tileSwap(chess->tile[r][c]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[row][col]);
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

    r=row;
    c=col;
    while(r-->0 && c++<7)
    {
        if(!chess->tile[r][c]->pieceObject)
        {
            if(checker)
            {
                chess->tile[row][col]->tileSwap(chess->tile[r][c]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[row][col]);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
        }

        else if(chess->tile[r][c]->pieceObject->pieceColor==this->pieceColor)
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }

        else if(chess->tile[r][c]->pieceObject->pieceColor!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r][c]);
                chess->tile[row][col]->tileSwap(chess->tile[r][c]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[row][col]);
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

    r=row;
    c=col;
    while(r-->0 && c-->0)
    {
        if(!chess->tile[r][c]->pieceObject)
        {
            if(checker)
            {
                chess->tile[row][col]->tileSwap(chess->tile[r][c]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[row][col]);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
        }

        else if(chess->tile[r][c]->pieceObject->pieceColor==this->pieceColor)
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }

        else if(chess->tile[r][c]->pieceObject->pieceColor!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r][c]);
                chess->tile[row][col]->tileSwap(chess->tile[r][c]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[row][col]);
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

    r=row;
    c=col;
    while(r++<7 && c++<7)
    {
        if(!chess->tile[r][c]->pieceObject)
        {
            if(checker)
            {
                chess->tile[row][col]->tileSwap(chess->tile[r][c]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[row][col]);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
        }

        else if(chess->tile[r][c]->pieceObject->pieceColor==this->pieceColor)
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }

        else if(chess->tile[r][c]->pieceObject->pieceColor!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r][c]);
                chess->tile[row][col]->tileSwap(chess->tile[r][c]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[row][col]);
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

    r=row;
    c=col;
    while(r++<7 && c-->0)
    {
        if(!chess->tile[r][c]->pieceObject)
        {
            if(checker)
            {
                chess->tile[row][col]->tileSwap(chess->tile[r][c]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[row][col]);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
        }

        else if(chess->tile[r][c]->pieceObject->pieceColor==this->pieceColor)
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }

        else if(chess->tile[r][c]->pieceObject->pieceColor!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r][c]);
                chess->tile[row][col]->tileSwap(chess->tile[r][c]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r][c]->tileSwap(chess->tile[row][col]);
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
