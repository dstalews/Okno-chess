#ifndef TILE_H
#define TILE_H
#include <QLabel>
#include <QDebug>
#include <piece.h>

class Tile: public QLabel
{
private:
    int tileColor,row,col,tileNum;
    Piece *pieceObject;
public:
    Tile(QWidget* pParent=0) : QLabel(pParent) {pieceObject = nullptr;};
    Tile(const QString& text, QWidget* pParent = 0) : QLabel(text, pParent){pieceObject = nullptr;};
    void setPiece(Piece *pieceObject);
    void mousePressEvent(QMouseEvent *event);
    void tileSwap(Tile *temp);
    void tileCopy(Tile *temp);
    void tileDisplay();
    void display();
    Piece* getPieceObject();
    void setPieceObject(Piece *newPiece);
    int getRow();
    int getCol();
    int getTileNum();
    void setParameters(int tileColor, int row, int col, int tileNum);
};

#endif // TILE_H
