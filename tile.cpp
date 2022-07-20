#include "tile.h"
#include "game.h"

extern Game *chess;

void Tile::mousePressEvent(QMouseEvent *event)
{
    if (event)
        chess->validate(this);
}

void Tile::display()
{

    if(this->pieceObject)
        this->setPixmap(QPixmap(QString::fromStdString(this->pieceObject->getImagePath())));
    else
        this->clear();
}

void Tile::tileDisplay()
{

    if(this->tileColor)
        this->setStyleSheet("QLabel {background-color: rgb(255, 128, 90);}:hover{background-color: rgb(170,85,127);}");
    else
        this->setStyleSheet("QLabel {background-color: rgb(255, 204, 153);}:hover{background-color: rgb(170,95,127);}");
}

void Tile::setPiece(Piece *pieceObject)
{
    this->pieceObject = pieceObject;
}

void Tile::tileSwap(Tile *temp)
{
    temp->pieceObject=this->pieceObject;
    this->pieceObject=nullptr;
}

void Tile::tileCopy(Tile *temp)
{
    this->pieceObject=temp->pieceObject;
    this->row=temp->row;
    this->col=temp->col;
}

Piece* Tile::getPieceObject()
{
    return pieceObject;
}

void Tile::setPieceObject(Piece *newPiece)
{
    pieceObject = newPiece;
}

int Tile::getRow()
{
    return row;
}

int Tile::getCol()
{
    return col;
}

int Tile::getTileNum()
{
    return tileNum;
}

void Tile::setParameters(int tileColor, int row, int col, int tileNum)
{
    this->tileColor = tileColor;
    this->row = row;
    this->col = col;
    this->tileNum = tileNum;
}
