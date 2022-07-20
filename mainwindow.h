#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>
#include <QMainWindow>
#include <QDockWidget>
#include <QFont>
#include "tile.h"

int const EXIT_CODE_REBOOT = -123456789;

class MainWindow : public QMainWindow
{
private:
    Q_OBJECT
    QPushButton *restart, *ranking, *whiteRook, *whiteHorse, *whiteBishop, *whiteQueen, *blackRook, *blackHorse, *blackBishop, *blackQueen;
    QLabel *player1Name, *player2Name;
    QLineEdit *typeP1name, *typeP2name;
    QDockWidget *ranks;
    void chessBoard();
    void outline(int xPos, int yPos, int Pos);
    void buttons();
    void slotReboot();
    void slotShowRanking();
    void slotWhiteRook();
    void slotWhiteHorse();
    void slotWhiteBishop();
    void slotWhiteQueen();
    void slotBlackRook();
    void slotBlackHorse();
    void slotBlackBishop();
    void slotBlackQueen();
    void slotSavePlayer1Name();
    void slotSavePlayer2Name();
public:
    MainWindow(QWidget* pParent = nullptr);
};

#endif // MAINWINDOW_H
