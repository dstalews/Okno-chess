#ifndef TILE_H
#define TILE_H
#include <QLabel>
#include <QDebug>
#include <piece.h>

class Tile: public QLabel
{
public:
    int tileColor,row,col,tileNum;
    Piece *pieceObject;
    Tile(QWidget* pParent=0) : QLabel(pParent) {pieceObject = nullptr;};
    Tile(const QString& text, QWidget* pParent = 0) : QLabel(text, pParent){pieceObject = nullptr;};
    void setPiece(Piece *pieceObject);
    void mousePressEvent(QMouseEvent *event);
    void tileSwap(Tile *temp);
    void tileCopy(Tile *temp);
    void tileDisplay();
    void display();
};

#endif // TILE_H
