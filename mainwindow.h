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
    Q_OBJECT
    QPushButton *restart, *ranking, *whiteRock, *whiteHorse, *whiteBishop, *whiteQueen, *blackRock, *blackHorse, *blackBishop, *blackQueen;
    QLabel *player1Name, *player2Name;
    QLineEdit *typeP1name, *typeP2name;
    QDockWidget *ranks;
public:
    MainWindow(QWidget* pParent = nullptr);
private:
    void chessBoard();
    void outline(int xPos, int yPos, int Pos);
    void buttons();
    void slotReboot();
    void slotShowRanking();
    void slotWhiteRock();
    void slotWhiteHorse();
    void slotWhiteBishop();
    void slotWhiteQueen();
    void slotBlackRock();
    void slotBlackHorse();
    void slotBlackBishop();
    void slotBlackQueen();
    void slotSavePlayer1Name();
    void slotSavePlayer2Name();
};

#endif // MAINWINDOW_H
