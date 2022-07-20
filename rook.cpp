#include "rook.h"
#include "game.h"

extern Game *chess;

Rook::Rook(int pieceColor)
{
    this->pieceColor = pieceColor;
    this->pieceName = 'R';
    if (pieceColor)
        this->imagePath = ":/Images/rook_white.svg";
    else
        this->imagePath = ":/Images/rook_black.svg";
}

int Rook::validate(int row, int col, int checker)
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

        else if(chess->tile[r][c]->pieceObject->getPieceColor()==this->pieceColor)
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }

        else if(chess->tile[r][c]->pieceObject->getPieceColor()!=this->pieceColor)
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

        else if(chess->tile[r][c]->pieceObject->getPieceColor()==this->pieceColor)
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }

        else if(chess->tile[r][c]->pieceObject->getPieceColor()!=this->pieceColor)
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

        else if(chess->tile[r][c]->pieceObject->getPieceColor()==this->pieceColor)
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }

        else if(chess->tile[r][c]->pieceObject->getPieceColor()!=this->pieceColor)
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

        else if(chess->tile[r][c]->pieceObject->getPieceColor()==this->pieceColor)
        {
            if (!checker)
            {
                chess->exp[chess->max++]=chess->tile[r][c]->tileNum;
                retVal=1;
            }
            break;
        }

        else if(chess->tile[r][c]->pieceObject->getPieceColor()!=this->pieceColor)
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
