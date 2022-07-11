#include "validation.h"
#include "game.h"

extern Game *chess;

Validation::Validation()
{
    //Nothing here
}

int Validation::chooser(Tile *temp, int checker)
{
    int flag;
    switch(temp->pieceName)
    {
    case 'P': flag=validatePawn(temp, checker);
              break;

    case 'R': flag=validateRook(temp, checker);
              break;

    case 'H': flag=validateHorse(temp, checker);
              break;

    case 'K': flag=validateKing(temp, checker);
              break;

    case 'Q': flag=validateQueen(temp, checker);
              break;

    case 'B': flag=validateBishop(temp, checker);
              break;

    }

    if (checker)
        chess->orange();

    return flag;
}

//PAWN
int Validation::validatePawn(Tile *temp, int checker)
{
    int row,col;

    row=temp->row;
    col=temp->col;
    int retVal=0, wcheck = 0;
    Tile *tmp = new Tile();

    //White Pawn
    if(temp->pieceColor)
    {
        if(row-1>=0 && !chess->tile[row-1][col]->piece && checker)
        {

            chess->tile[row][col]->tileSwap(chess->tile[row-1][col]);
            wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
            chess->tile[row-1][col]->tileSwap(chess->tile[row][col]);

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[row-1][col]->tileNum;
                retVal=1;
            }
        }

        if(row==6 && !chess->tile[5][col]->piece && !chess->tile[4][col]->piece && checker)
        {

            chess->tile[row][col]->tileSwap(chess->tile[row-2][col]);
            wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
            chess->tile[row-2][col]->tileSwap(chess->tile[row][col]);

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[row-2][col]->tileNum;
                retVal=1;
            }
        }

        if(row-1>=0 && col-1>=0)
        {
            if(chess->tile[row-1][col-1]->pieceColor!=temp->pieceColor && chess->tile[row-1][col-1]->piece)
            {
                if(checker)
                {
                    tmp->tileCopy(chess->tile[row-1][col-1]);
                    chess->tile[row][col]->tileSwap(chess->tile[row-1][col-1]);
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
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
            if(chess->tile[row-1][col+1]->pieceColor!=temp->pieceColor && chess->tile[row-1][col+1]->piece)
            {

                if(checker)
                {
                    tmp->tileCopy(chess->tile[row-1][col+1]);
                    chess->tile[row][col]->tileSwap(chess->tile[row-1][col+1]);
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
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
            if(chess->tile[row][col+1]->pieceColor!=temp->pieceColor && chess->tile[row][col+1]->pieceName=='P' && chess->tile[row][col+1]->en+1==chess->turnAll)
            {

                chess->tile[row][col]->tileSwap(chess->tile[row-1][col+1]);
                chess->tile[row][col+1]->piece = 0;
                wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                chess->tile[row-1][col+1]->tileSwap(chess->tile[row][col]);
                chess->tile[row][col+1]->piece = 1;

                if (!wcheck)
                {
                    chess->exp[chess->max++]=chess->tile[row-1][col+1]->tileNum;
                    retVal=1;
                }
            }
        }

        if(row==3 && col-1>=0 && checker)
        {
            if(chess->tile[row][col-1]->pieceColor!=temp->pieceColor && chess->tile[row][col-1]->pieceName=='P' && chess->tile[row][col-1]->en+1==chess->turnAll)
            {
                chess->tile[row][col]->tileSwap(chess->tile[row-1][col-1]);
                chess->tile[row][col-1]->piece = 0;
                wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                chess->tile[row-1][col-1]->tileSwap(chess->tile[row][col]);
                chess->tile[row][col-1]->piece = 1;

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
        if(row+1<=7 && !chess->tile[row+1][col]->piece  && checker)
        {
            chess->tile[row][col]->tileSwap(chess->tile[row+1][col]);
            wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
            chess->tile[row+1][col]->tileSwap(chess->tile[row][col]);

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[row+1][col]->tileNum;
                retVal=1;
            }
        }

        if(row==1 && !chess->tile[2][col]->piece && !chess->tile[3][col]->piece  && checker)
        {
            chess->tile[row][col]->tileSwap(chess->tile[row+2][col]);
            wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
            chess->tile[row+2][col]->tileSwap(chess->tile[row][col]);

            if (!wcheck)
            {
                chess->exp[chess->max++]=chess->tile[row+2][col]->tileNum;
                retVal=1;
            }
        }

        if(row+1<=7 && col-1>=0)
        {
            if(chess->tile[row+1][col-1]->pieceColor!=temp->pieceColor && chess->tile[row+1][col-1]->piece)
            {
                if(checker)
                {
                    tmp->tileCopy(chess->tile[row+1][col-1]);
                    chess->tile[row][col]->tileSwap(chess->tile[row+1][col-1]);
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
            if(chess->tile[row+1][col+1]->pieceColor!=temp->pieceColor && chess->tile[row+1][col+1]->piece)
            {
                if(checker)
                {
                    tmp->tileCopy(chess->tile[row+1][col+1]);
                    chess->tile[row][col]->tileSwap(chess->tile[row+1][col+1]);
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
            if(chess->tile[row][col+1]->pieceColor!=temp->pieceColor && chess->tile[row][col+1]->pieceName=='P' && chess->tile[row][col+1]->en+1==chess->turnAll)
            {
                chess->tile[row][col]->tileSwap(chess->tile[row+1][col+1]);
                chess->tile[row][col+1]->piece = 0;
                wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[row+1][col+1]->tileSwap(chess->tile[row][col]);
                chess->tile[row][col+1]->piece = 1;

                if (!wcheck)
                {
                    chess->exp[chess->max++]=chess->tile[row+1][col+1]->tileNum;
                    retVal=1;
                }
            }
        }

        if(row==4 && col-1>=0  && checker)
        {
            if(chess->tile[row][col-1]->pieceColor!=temp->pieceColor && chess->tile[row][col-1]->pieceName=='P' && chess->tile[row][col-1]->en+1==chess->turnAll)
            {
                chess->tile[row][col]->tileSwap(chess->tile[row+1][col-1]);
                chess->tile[row][col-1]->piece = 0;
                wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[row+1][col-1]->tileSwap(chess->tile[row][col]);
                chess->tile[row][col-1]->piece = 1;

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


//ROOK
int Validation::validateRook(Tile *temp, int checker)
{
    int r,c;

    int retVal=0, wcheck = 0;
    Tile *tmp = new Tile();

    r=temp->row;
    c=temp->col;
    while(r-->0)
    {
        if(!chess->tile[r][c]->piece)
        {
            if(checker)
            {
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c]);
                if (temp->pieceColor)
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
    while(r++<7)
    {
        if(!chess->tile[r][c]->piece)
        {
            if(checker)
            {
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c]);
                if (temp->pieceColor)
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
    while(c++<7)
    {
        if(!chess->tile[r][c]->piece)
        {
            if(checker)
            {
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c]);
                if (temp->pieceColor)
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
    while(c-->0)
    {
        if(!chess->tile[r][c]->piece)
        {
            if(checker)
            {
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c]);
                if (temp->pieceColor)
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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


//HORSE
int Validation::validateHorse(Tile *temp, int checker)
{
    int r,c;
    int retVal=0, wcheck = 0;
    Tile *tmp = new Tile();

    r=temp->row;
    c=temp->col;

    if(r-2>=0 && c-1>=0)
    {
        if(chess->tile[r-2][c-1]->pieceColor!=temp->pieceColor || !chess->tile[r-2][c-1]->piece)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r-2][c-1]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r-2][c-1]);
                if (temp->pieceColor)
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[r-2][c-1]->tileSwap(chess->tile[temp->row][temp->col]);
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
        if(chess->tile[r-2][c+1]->pieceColor!=temp->pieceColor || !chess->tile[r-2][c+1]->piece)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r-2][c+1]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r-2][c+1]);
                if (temp->pieceColor)
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[r-2][c+1]->tileSwap(chess->tile[temp->row][temp->col]);
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
        if(chess->tile[r-1][c-2]->pieceColor!=temp->pieceColor || !chess->tile[r-1][c-2]->piece)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r-1][c-2]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r-1][c-2]);
                if (temp->pieceColor)
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[r-1][c-2]->tileSwap(chess->tile[temp->row][temp->col]);
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
        if(chess->tile[r-1][c+2]->pieceColor!=temp->pieceColor || !chess->tile[r-1][c+2]->piece)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r-1][c+2]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r-1][c+2]);
                if (temp->pieceColor)
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[r-1][c+2]->tileSwap(chess->tile[temp->row][temp->col]);
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
        if(chess->tile[r+2][c+1]->pieceColor!=temp->pieceColor || !chess->tile[r+2][c+1]->piece)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r+2][c+1]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r+2][c+1]);
                if (temp->pieceColor)
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[r+2][c+1]->tileSwap(chess->tile[temp->row][temp->col]);
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
        if(chess->tile[r+2][c-1]->pieceColor!=temp->pieceColor || !chess->tile[r+2][c-1]->piece)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r+2][c-1]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r+2][c-1]);
                if (temp->pieceColor)
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[r+2][c-1]->tileSwap(chess->tile[temp->row][temp->col]);
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
        if(chess->tile[r+1][c-2]->pieceColor!=temp->pieceColor || !chess->tile[r+1][c-2]->piece)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r+1][c-2]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r+1][c-2]);
                if (temp->pieceColor)
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[r+1][c-2]->tileSwap(chess->tile[temp->row][temp->col]);
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
        if(chess->tile[r+1][c+2]->pieceColor!=temp->pieceColor || !chess->tile[r+1][c+2]->piece)
        {
            if(checker)
            {
                tmp->tileCopy(chess->tile[r+1][c+2]);
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r+1][c+2]);
                if (temp->pieceColor)
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
                chess->tile[r+1][c+2]->tileSwap(chess->tile[temp->row][temp->col]);
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


//KING
int Validation::validateKing(Tile *temp, int checker)
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
                wcheck = check(r-1,c,temp->pieceColor);
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
                wcheck = check(r+1,c,temp->pieceColor);
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
                wcheck = check(r,c-1,temp->pieceColor);
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
                wcheck = check(r,c+1,temp->pieceColor);
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
                wcheck = check(r-1,c-1,temp->pieceColor);
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
                wcheck = check(r-1,c+1,temp->pieceColor);
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
                wcheck = check(r+1,c-1,temp->pieceColor);
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
                wcheck = check(r+1,c+1,temp->pieceColor);
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

    if(r==0 && c==4 && !temp->pieceColor && !temp->en && checker && !check(r,c,temp->pieceColor))
    {
        if(chess->tile[0][7]->piece && !chess->tile[0][6]->piece && !chess->tile[0][5]->piece && chess->tile[0][7]->pieceName == 'R' &&
                !check(0,6,temp->pieceColor) && !check(0,5,temp->pieceColor) && !chess->tile[0][7]->pieceColor && !chess->tile[0][7]->en)
        {
            chess->exp[chess->max++]=chess->tile[r][c+2]->tileNum;
            retVal=1;
        }
        if(chess->tile[0][0]->piece && !chess->tile[0][3]->piece && !chess->tile[0][2]->piece && !chess->tile[0][1]->piece && chess->tile[0][0]->pieceName == 'R' &&
                !check(0,3,temp->pieceColor) && !check(0,2,temp->pieceColor) && !check(0,1,temp->pieceColor) && !chess->tile[0][0]->pieceColor && !chess->tile[0][0]->en)
        {
            chess->exp[chess->max++]=chess->tile[r][c-2]->tileNum;
            retVal=1;
        }
    }

    if(r==7 && c==4 && temp->pieceColor && !temp->en && !check(r,c,temp->pieceColor) && checker)
    {
        if(chess->tile[7][7]->piece && !chess->tile[7][6]->piece && !chess->tile[7][5]->piece && chess->tile[7][7]->pieceName == 'R' &&
                !check(7,6,temp->pieceColor) && !check(7,5,temp->pieceColor) && chess->tile[7][7]->pieceColor && !chess->tile[7][7]->en)
        {
            chess->exp[chess->max++]=chess->tile[r][c+2]->tileNum;
            retVal=1;
        }
        if(chess->tile[7][0]->piece && !chess->tile[7][3]->piece && !chess->tile[7][2]->piece && !chess->tile[7][1]->piece && chess->tile[7][0]->pieceName == 'R' &&
                !check(7,3,temp->pieceColor) && !check(7,2,temp->pieceColor) && !check(7,1,temp->pieceColor) && chess->tile[7][0]->pieceColor && !chess->tile[7][0]->en)
        {
            chess->exp[chess->max++]=chess->tile[r][c-2]->tileNum;
            retVal=1;
        }
    }

    delete tmp;
    return retVal;
}

//QUEEN
int Validation::validateQueen(Tile *temp, int checker)
{
    int r,c;

    int retVal=0, wcheck = 0;
    Tile *tmp = new Tile();

    r=temp->row;
    c=temp->col;
    while(r-->0)
    {
        if(!chess->tile[r][c]->piece)
        {
            if(checker)
            {
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c]);
                if (temp->pieceColor)
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
    while(r++<7)
    {
        if(!chess->tile[r][c]->piece)
        {
            if(checker)
            {
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c]);
                if (temp->pieceColor)
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
    while(c++<7)
    {
        if(!chess->tile[r][c]->piece)
        {
            if(checker)
            {
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c]);
                if (temp->pieceColor)
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
    while(c-->0)
    {
        if(!chess->tile[r][c]->piece)
        {
            if(checker)
            {
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c]);
                if (temp->pieceColor)
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
    while(r-->0 && c++<7)
    {
        if(!chess->tile[r][c]->piece)
        {
            if(checker)
            {
                chess->tile[temp->row][temp->col]->tileSwap(chess->tile[r][c]);
                if (temp->pieceColor)
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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

//BISHOP
int Validation::validateBishop(Tile *temp, int checker)
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
                else
                    wcheck = check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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

int Validation::check(int r,int c, int color)
{

    int i, j, k, tmp = chess->max;

    for (i=0;i<8;i++)
    {
        for (j=0;j<8;j++)
        {
            if (chess->tile[i][j]->pieceColor != color && chess->tile[i][j]->piece && (i!=r || j !=c))
            {
                chooser(chess->tile[i][j],0);
                for(k=tmp;k<chess->max;k++)
                {
                    if (chess->exp[k]/8 == r && chess->exp[k]%8 == c)
                    {
                        chess->max = tmp;
                        return 1;
                    }
                }
                chess->max = tmp;
            }
        }
    }

    return 0;
}
