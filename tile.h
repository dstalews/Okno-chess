#ifndef TILE_H
#define TILE_H
#include <QLabel>
#include <QDebug>

class Tile: public QLabel
{
public:
    int tileColor,piece,pieceColor,row,col,tileNum,en=0;
    char pieceName;
    Tile(QWidget* pParent=0) : QLabel(pParent) {};
    Tile(const QString& text, QWidget* pParent = 0) : QLabel(text, pParent){};
    void mousePressEvent(QMouseEvent *event);
    void tileSwap(Tile *temp);
    void tileCopy(Tile *temp);
    void tileDisplay();
    void display(char elem);
};

#endif // TILE_H
