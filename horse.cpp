#include "horse.h"
#include "game.h"

extern Game *chess;

Horse::Horse(int pieceColor)
{
    this->pieceColor = pieceColor;
    this->pieceName = 'H';
    if (pieceColor)
        this->image_path = ":/Images/knight_white.svg";
    else
        this->image_path = ":/Images/knight_black.svg";
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
        if(chess->tile[r-2][c-1]->pieceObject==nullptr || chess->tile[r-2][c-1]->pieceObject->pieceColor!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r-2][c-1]);
                chess->tile[row][col]->tileSwap(chess->tile[r-2][c-1]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r-2][c-1]->tileSwap(chess->tile[row][col]);
                chess->tile[r-2][c-1]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r-2][c-1]->tileNum;
                retVal=1;
            }
        }
        else
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r-2][c-1]->tileNum;
                retVal=1;
            }
        }
    }

    if(r-2>=0 && c+1<=7)
    {
        if(chess->tile[r-2][c+1]->pieceObject==nullptr||chess->tile[r-2][c+1]->pieceObject->pieceColor!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r-2][c+1]);
                chess->tile[row][col]->tileSwap(chess->tile[r-2][c+1]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r-2][c+1]->tileSwap(chess->tile[row][col]);
                chess->tile[r-2][c+1]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r-2][c+1]->tileNum;
                retVal=1;
            }
        }
        else
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r-2][c+1]->tileNum;
                retVal=1;
            }
        }
    }

    if(r-1>=0 && c-2>=0)
    {
        if(chess->tile[r-1][c-2]->pieceObject==nullptr||chess->tile[r-1][c-2]->pieceObject->pieceColor!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r-1][c-2]);
                chess->tile[row][col]->tileSwap(chess->tile[r-1][c-2]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r-1][c-2]->tileSwap(chess->tile[row][col]);
                chess->tile[r-1][c-2]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r-1][c-2]->tileNum;
                retVal=1;
            }
        }
        else
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r-1][c-2]->tileNum;
                retVal=1;
            }
        }
    }

    if(r-1>=0 && c+2<=7)
    {
        if(chess->tile[r-1][c+2]->pieceObject==nullptr || chess->tile[r-1][c+2]->pieceObject->pieceColor!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r-1][c+2]);
                chess->tile[row][col]->tileSwap(chess->tile[r-1][c+2]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r-1][c+2]->tileSwap(chess->tile[row][col]);
                chess->tile[r-1][c+2]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r-1][c+2]->tileNum;
                retVal=1;
            }
        }
        else
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r-1][c+2]->tileNum;
                retVal=1;
            }
        }
    }

    if(r+2<=7 && c+1<=7)
    {
        if(chess->tile[r+2][c+1]->pieceObject == nullptr || chess->tile[r+2][c+1]->pieceObject->pieceColor!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r+2][c+1]);
                chess->tile[row][col]->tileSwap(chess->tile[r+2][c+1]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r+2][c+1]->tileSwap(chess->tile[row][col]);
                chess->tile[r+2][c+1]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r+2][c+1]->tileNum;
                retVal=1;
            }
        }
        else
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r+2][c+1]->tileNum;
                retVal=1;
            }
        }
    }

    if(r+2<=7 && c-1>=0)
    {
        if(chess->tile[r+2][c-1]->pieceObject==nullptr || chess->tile[r+2][c-1]->pieceObject->pieceColor!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r+2][c-1]);
                chess->tile[row][col]->tileSwap(chess->tile[r+2][c-1]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r+2][c-1]->tileSwap(chess->tile[row][col]);
                chess->tile[r+2][c-1]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r+2][c-1]->tileNum;
                retVal=1;
            }
        }
        else
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r+2][c-1]->tileNum;
                retVal=1;
            }
        }
    }

    if(r+1<=7 && c-2>=0)
    {
        if(chess->tile[r+1][c-2]->pieceObject==nullptr||chess->tile[r+1][c-2]->pieceObject->pieceColor!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r+1][c-2]);
                chess->tile[row][col]->tileSwap(chess->tile[r+1][c-2]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r+1][c-2]->tileSwap(chess->tile[row][col]);
                chess->tile[r+1][c-2]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r+1][c-2]->tileNum;
                retVal=1;
            }
        }
        else
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r+1][c-2]->tileNum;
                retVal=1;
            }
        }
    }

    if(r+1<=7 && c+2<=7)
    {
        if(chess->tile[r+1][c+2]->pieceObject==nullptr||chess->tile[r+1][c+2]->pieceObject->pieceColor!=this->pieceColor)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r+1][c+2]);
                chess->tile[row][col]->tileSwap(chess->tile[r+1][c+2]);
                if (this->pieceColor)
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,this->pieceColor);
                else
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,this->pieceColor);
                chess->tile[r+1][c+2]->tileSwap(chess->tile[row][col]);
                chess->tile[r+1][c+2]->tileCopy(tmp);
            }

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[r+1][c+2]->tileNum;
                retVal=1;
            }
        }
        else
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r+1][c+2]->tileNum;
                retVal=1;
            }
        }
    }

    delete tmp;
    return retVal;
}
