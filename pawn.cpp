#include "pawn.h"
#include "game.h"

extern Game *chess;

Pawn::Pawn(int pieceColor)
{
    this->pieceColor = pieceColor;
    this->pieceName = 'P';
    if (pieceColor)
        this->image_path = ":/Images/pawn_white.svg";
    else
        this->image_path = ":/Images/pawn_black.svg";
}

int Pawn::validate(Tile *temp, int checker)
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
            wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
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
            wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
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
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
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
                    wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
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
                wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
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
                wcheck = chess->check(chess->whiteKing->row,chess->whiteKing->col,temp->pieceColor);
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
            wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
            wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                    wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
                wcheck = chess->check(chess->blackKing->row,chess->blackKing->col,temp->pieceColor);
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
