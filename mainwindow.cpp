#include "mainwindow.h"
#include "game.h"

extern Game *chess;

MainWindow::MainWindow(QWidget* pParent) : QMainWindow(pParent) {
    this->setGeometry(0,0,850,552);
    chess->newLabel(this);
    chess->resetVariables();
    this->buttons();
    this->chessBoard();
};

void MainWindow::slotReboot() {

    qDebug() << "Performing application reboot...";
    // reset global variables
    chess->resetVariables();
    qApp->exit( EXIT_CODE_REBOOT );
}

void MainWindow::slotShowRanking() {

    ranks = new QDockWidget(this);

    ranks->setWindowTitle("Ranking");
    ranks->setFloating(true);
    ranks->setStyleSheet("QDockWidget { font: bold }");
    ranks->setAllowedAreas( Qt::LeftDockWidgetArea  );
    ranks->setGeometry(250,100,350,500);

    QLabel *text = new QLabel(ranks);
    QFont f( "Arial", 16, QFont::Bold);
    if (chess->getRanks()->getRanking() != "")
        text->setText(QString::fromStdString(chess->getRanks()->getRanking()));
    else
        text->setText(" ");
    text->setGeometry(0,0,350,500);
    text->setFont( f);
    text->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    this->addDockWidget(Qt::LeftDockWidgetArea,ranks);
}

void MainWindow::slotWhiteRook() {

    chess->setPromotion('R',1);
    whiteRook->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    whiteQueen->setStyleSheet("QPushButton {background-color: none;}");
    whiteHorse->setStyleSheet("QPushButton {background-color: none;}");
    whiteBishop->setStyleSheet("QPushButton {background-color: none;}");

}

void MainWindow::slotWhiteHorse() {

    chess->setPromotion('H',1);
    whiteHorse->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    whiteQueen->setStyleSheet("QPushButton {background-color: none;}");
    whiteRook->setStyleSheet("QPushButton {background-color: none;}");
    whiteBishop->setStyleSheet("QPushButton {background-color: none;}");

}

void MainWindow::slotWhiteBishop() {

    chess->setPromotion('B',1);
    whiteBishop->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    whiteQueen->setStyleSheet("QPushButton {background-color: none;}");
    whiteHorse->setStyleSheet("QPushButton {background-color: none;}");
    whiteRook->setStyleSheet("QPushButton {background-color: none;}");

}

void MainWindow::slotWhiteQueen() {

    chess->setPromotion('Q',1);
    whiteQueen->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    whiteRook->setStyleSheet("QPushButton {background-color: none;}");
    whiteHorse->setStyleSheet("QPushButton {background-color: none;}");
    whiteBishop->setStyleSheet("QPushButton {background-color: none;}");

}

void MainWindow::slotBlackRook() {

    chess->setPromotion('R',0);
    blackRook->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    blackQueen->setStyleSheet("QPushButton {background-color: none;}");
    blackHorse->setStyleSheet("QPushButton {background-color: none;}");
    blackBishop->setStyleSheet("QPushButton {background-color: none;}");

}

void MainWindow::slotBlackHorse() {

    chess->setPromotion('H',0);
    blackHorse->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    blackQueen->setStyleSheet("QPushButton {background-color: none;}");
    blackRook->setStyleSheet("QPushButton {background-color: none;}");
    blackBishop->setStyleSheet("QPushButton {background-color: none;}");

}

void MainWindow::slotBlackBishop() {

    chess->setPromotion('B',0);
    blackBishop->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    blackQueen->setStyleSheet("QPushButton {background-color: none;}");
    blackHorse->setStyleSheet("QPushButton {background-color: none;}");
    blackRook->setStyleSheet("QPushButton {background-color: none;}");

}

void MainWindow::slotBlackQueen() {

    chess->setPromotion('Q',0);
    blackQueen->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    blackRook->setStyleSheet("QPushButton {background-color: none;}");
    blackHorse->setStyleSheet("QPushButton {background-color: none;}");
    blackBishop->setStyleSheet("QPushButton {background-color: none;}");

}

void MainWindow::slotSavePlayer1Name() {

    if (typeP1name->isModified() && (!chess->getPlayer(2) || chess->getPlayer(2)->getPlayerName().compare(typeP1name->text().toStdString()) != 0))
    {
        std::string str = typeP1name->text().toStdString();
        str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
        chess->setPlayer(1,str,chess->getRanks()->getPlayerPoints(str));
        player1Name->setText("Name: " +QString::fromStdString(chess->getPlayer(1)->getPlayerName()) + "       LP: "+QString::fromStdString(std::to_string(chess->getPlayer(1)->getPlayerPoints())));
        player1Name->setAlignment(Qt::AlignCenter);
        player1Name->setFrameStyle(QFrame::NoFrame);
        player1Name->setGeometry(572,120,250,50);

        delete typeP1name;
    }

}

void MainWindow::slotSavePlayer2Name() {

    if (typeP2name->isModified() && (!chess->getPlayer(1) || chess->getPlayer(1)->getPlayerName().compare(typeP2name->text().toStdString()) != 0))
    {
        std::string str = typeP2name->text().toStdString();
        str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
        chess->setPlayer(2,str,chess->getRanks()->getPlayerPoints(str));
        player2Name->setText("Name: " +QString::fromStdString(chess->getPlayer(2)->getPlayerName()) + "       LP: "+QString::fromStdString(std::to_string(chess->getPlayer(2)->getPlayerPoints())));
        player2Name->setAlignment(Qt::AlignCenter);
        player2Name->setFrameStyle(QFrame::NoFrame);
        player2Name->setGeometry(572,270,250,50);


        delete typeP2name;
    }

}

void MainWindow::buttons()
{
    restart = new QPushButton("&Restart", this);
    ranking = new QPushButton("&Ranking", this);
    whiteRook = new QPushButton("&R", this);
    whiteHorse = new QPushButton("&H", this);
    whiteBishop = new QPushButton("&B", this);
    whiteQueen = new QPushButton("&Q", this);
    blackRook = new QPushButton("&R", this);
    blackHorse = new QPushButton("&H", this);
    blackBishop = new QPushButton("&B", this);
    blackQueen = new QPushButton("&Q", this);
    player1Name = new QLabel("Player1",this);
    player2Name = new QLabel("Player2",this);

    QLabel *Wpromo = new QLabel("Active White Pawn Promotion:",this);
    QLabel *Bpromo = new QLabel("Active Black Pawn Promotion:",this);
    Wpromo->setAlignment(Qt::AlignCenter);
    Bpromo->setAlignment(Qt::AlignCenter);
    Wpromo->setFrameStyle(QFrame::NoFrame);
    Bpromo->setFrameStyle(QFrame::NoFrame);
    Wpromo->setGeometry(572,150,250,50);
    Bpromo->setGeometry(572,300,250,50);

    restart->setGeometry(572,20,250,40);
    ranking->setGeometry(572,70,250,40);
    whiteRook->setGeometry(572,200,50,50);
    whiteHorse->setGeometry(638,200,50,50);
    whiteBishop->setGeometry(704,200,50,50);
    whiteQueen->setGeometry(770,200,50,50);

    blackRook->setGeometry(572,350,50,50);
    blackHorse->setGeometry(638,350,50,50);
    blackBishop->setGeometry(704,350,50,50);
    blackQueen->setGeometry(770,350,50,50);

    whiteQueen->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    blackQueen->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");

    QObject::connect(restart, &QPushButton::released, this, &MainWindow::slotReboot);
    QObject::connect(ranking, &QPushButton::released, this, &MainWindow::slotShowRanking);
    QObject::connect(whiteRook, &QPushButton::released, this, &MainWindow::slotWhiteRook);
    QObject::connect(whiteHorse, &QPushButton::released, this, &MainWindow::slotWhiteHorse);
    QObject::connect(whiteBishop, &QPushButton::released, this, &MainWindow::slotWhiteBishop);
    QObject::connect(whiteQueen, &QPushButton::released, this, &MainWindow::slotWhiteQueen);
    QObject::connect(blackRook, &QPushButton::released, this, &MainWindow::slotBlackRook);
    QObject::connect(blackHorse, &QPushButton::released, this, &MainWindow::slotBlackHorse);
    QObject::connect(blackBishop, &QPushButton::released, this, &MainWindow::slotBlackBishop);
    QObject::connect(blackQueen, &QPushButton::released, this, &MainWindow::slotBlackQueen);

    typeP1name = new QLineEdit(this);
    typeP1name->setGeometry(572,120,250,40);
    typeP1name->setPlaceholderText("Type Player1 name");
    QObject::connect(typeP1name, &QLineEdit::returnPressed, this, &MainWindow::slotSavePlayer1Name);
    typeP2name = new QLineEdit(this);
    typeP2name->setGeometry(572,270,250,40);
    typeP2name->setPlaceholderText("Type Player2 name");
    QObject::connect(typeP2name, &QLineEdit::returnPressed, this, &MainWindow::slotSavePlayer2Name);

}

void MainWindow::outline(int xPos, int yPos, int Pos)
{
     QLabel *outLabel = new QLabel(this);

    if(!Pos)
        outLabel->setGeometry(xPos,yPos,552,20);        //Horizontal Borders

    else
        outLabel->setGeometry(xPos,yPos,20,512);        //Vertical Borders

    outLabel->setStyleSheet("QLabel { background-color :rgb(204, 102, 0); color : black; }");
}

void MainWindow::chessBoard()
{
    int i,j,k=0,hor,ver;

    //borderDisplay
    {
    this->outline(0,0,0);
    this->outline(0,532,0);
    this->outline(0,20,1);
    this->outline(532,20,1);
    }

    //Create 64 tiles (allocating memories to the objects of Tile class)
    ver=20;
    for(i=0;i<8;i++)
    {
        hor=20;
        for(j=0;j<8;j++)
        {
            chess->newTile(i,j,this);
            chess->getTile(i,j)->tileColor=(i+j)%2;
            chess->getTile(i,j)->row=i;
            chess->getTile(i,j)->col=j;
            chess->getTile(i,j)->tileNum=k++;
            chess->getTile(i,j)->tileDisplay();
            chess->getTile(i,j)->setGeometry(hor,ver,64,64);
            hor+=64;
        }
        ver+=64;
    }

    //black pawns
    for(j=0;j<8;j++)
    {
        chess->getTile(1,j)->setPiece(new Pawn(0));
        chess->getTile(1,j)->display();

    }

    //white pawns
    for(j=0;j<8;j++)
    {
        chess->getTile(6,j)->setPiece(new Pawn(1));
        chess->getTile(6,j)->display();
    }

    {
    chess->getTile(0,0)->setPiece(new Rook(0));
    chess->getTile(0,0)->display();
    chess->getTile(0,1)->setPiece(new Horse(0));
    chess->getTile(0,1)->display();
    chess->getTile(0,2)->setPiece(new Bishop(0));
    chess->getTile(0,2)->display();
    chess->getTile(0,3)->setPiece(new Queen(0));
    chess->getTile(0,3)->display();
    chess->getTile(0,4)->setPiece(new King(0));
    chess->getTile(0,4)->display();
    chess->getTile(0,5)->setPiece(new Bishop(0));
    chess->getTile(0,5)->display();
    chess->getTile(0,6)->setPiece(new Horse(0));
    chess->getTile(0,6)->display();
    chess->getTile(0,7)->setPiece(new Rook(0));
    chess->getTile(0,7)->display();
    }


    {
    chess->getTile(7,0)->setPiece(new Rook(1));
    chess->getTile(7,0)->display();
    chess->getTile(7,1)->setPiece(new Horse(1));
    chess->getTile(7,1)->display();
    chess->getTile(7,2)->setPiece(new Bishop(1));
    chess->getTile(7,2)->display();
    chess->getTile(7,3)->setPiece(new Queen(1));
    chess->getTile(7,3)->display();
    chess->getTile(7,4)->setPiece(new King(1));
    chess->getTile(7,4)->display();
    chess->getTile(7,5)->setPiece(new Bishop(1));
    chess->getTile(7,5)->display();
    chess->getTile(7,6)->setPiece(new Horse(1));
    chess->getTile(7,6)->display();
    chess->getTile(7,7)->setPiece(new Rook(1));
    chess->getTile(7,7)->display();
    }
    //remember Kings positions
    chess->getBlackKing()->tileCopy(chess->getTile(0,4));
    chess->getWhiteKing()->tileCopy(chess->getTile(7,4));
}

