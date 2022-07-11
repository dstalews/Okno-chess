#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"
#include "tile.h"
#include "game.h"

Game *chess = new Game();

int main(int argc, char *argv[])
{
    int currentExitCode = 0;
    do {
        QApplication a(argc, argv);
        MainWindow *Chess_game = new MainWindow();
        Chess_game->show();
        currentExitCode = a.exec();
    } while( currentExitCode == EXIT_CODE_REBOOT );

    return currentExitCode;
}

