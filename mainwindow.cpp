#include "mainwindow.h"
#include "game.h"

extern Game *chess;

MainWindow::MainWindow(QWidget* pParent) : QMainWindow(pParent) {
    this->setGeometry(0,0,850,552);
    chess->label = new QLabel(this);
    this->buttons();
    this->chessBoard();
};

void MainWindow::slotReboot() {

    qDebug() << "Performing application reboot...";
    // reset global variables
    chess->count=0;
    chess->turn=1;
    chess->max=0;
    chess->turnAll=1;
    chess->whitePromotion = 'Q';
    chess->blackPromotion = 'Q';
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
    if (chess->ranking->getRanking() != "")
        text->setText(QString::fromStdString(chess->ranking->getRanking()));
    else
        text->setText(" ");
    text->setGeometry(0,0,350,500);
    text->setFont( f);
    text->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    this->addDockWidget(Qt::LeftDockWidgetArea,ranks);
}

void MainWindow::slotWhiteRock() {

    chess->whitePromotion = 'R';
    whiteRock->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    whiteQueen->setStyleSheet("QPushButton {background-color: none;}");
    whiteHorse->setStyleSheet("QPushButton {background-color: none;}");
    whiteBishop->setStyleSheet("QPushButton {background-color: none;}");

}

void MainWindow::slotWhiteHorse() {

    chess->whitePromotion = 'H';
    whiteHorse->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    whiteQueen->setStyleSheet("QPushButton {background-color: none;}");
    whiteRock->setStyleSheet("QPushButton {background-color: none;}");
    whiteBishop->setStyleSheet("QPushButton {background-color: none;}");

}

void MainWindow::slotWhiteBishop() {

    chess->whitePromotion = 'B';
    whiteBishop->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    whiteQueen->setStyleSheet("QPushButton {background-color: none;}");
    whiteHorse->setStyleSheet("QPushButton {background-color: none;}");
    whiteRock->setStyleSheet("QPushButton {background-color: none;}");

}

void MainWindow::slotWhiteQueen() {

    chess->whitePromotion = 'Q';
    whiteQueen->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    whiteRock->setStyleSheet("QPushButton {background-color: none;}");
    whiteHorse->setStyleSheet("QPushButton {background-color: none;}");
    whiteBishop->setStyleSheet("QPushButton {background-color: none;}");

}

void MainWindow::slotBlackRock() {

    chess->blackPromotion = 'R';
    blackRock->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    blackQueen->setStyleSheet("QPushButton {background-color: none;}");
    blackHorse->setStyleSheet("QPushButton {background-color: none;}");
    blackBishop->setStyleSheet("QPushButton {background-color: none;}");

}

void MainWindow::slotBlackHorse() {

    chess->blackPromotion = 'H';
    blackHorse->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    blackQueen->setStyleSheet("QPushButton {background-color: none;}");
    blackRock->setStyleSheet("QPushButton {background-color: none;}");
    blackBishop->setStyleSheet("QPushButton {background-color: none;}");

}

void MainWindow::slotBlackBishop() {

    chess->blackPromotion = 'B';
    blackBishop->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    blackQueen->setStyleSheet("QPushButton {background-color: none;}");
    blackHorse->setStyleSheet("QPushButton {background-color: none;}");
    blackRock->setStyleSheet("QPushButton {background-color: none;}");

}

void MainWindow::slotBlackQueen() {

    chess->blackPromotion = 'Q';
    blackQueen->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    blackRock->setStyleSheet("QPushButton {background-color: none;}");
    blackHorse->setStyleSheet("QPushButton {background-color: none;}");
    blackBishop->setStyleSheet("QPushButton {background-color: none;}");

}

void MainWindow::slotSavePlayer1Name() {

    if (typeP1name->isModified() && (!chess->player2 || chess->player2->getPlayerName().compare(typeP1name->text().toStdString()) != 0))
    {
        std::string str = typeP1name->text().toStdString();
        str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
        chess->player1 = new Player(str,chess->ranking->getPlayerPoints(str));
        player1Name->setText("Name: " +QString::fromStdString(chess->player1->getPlayerName()) + "       LP: "+QString::fromStdString(std::to_string(chess->player1->getPlayerPoints())));
        player1Name->setAlignment(Qt::AlignCenter);
        player1Name->setFrameStyle(QFrame::NoFrame);
        player1Name->setGeometry(572,120,250,50);

        delete typeP1name;
    }

}

void MainWindow::slotSavePlayer2Name() {

    if (typeP2name->isModified() && (!chess->player1 || chess->player1->getPlayerName().compare(typeP2name->text().toStdString()) != 0))
    {
        std::string str = typeP2name->text().toStdString();
        str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
        chess->player2 = new Player(str,chess->ranking->getPlayerPoints(str));
        player2Name->setText("Name: " +QString::fromStdString(chess->player2->getPlayerName()) + "       LP: "+QString::fromStdString(std::to_string(chess->player2->getPlayerPoints())));
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
    whiteRock = new QPushButton("&R", this);
    whiteHorse = new QPushButton("&H", this);
    whiteBishop = new QPushButton("&B", this);
    whiteQueen = new QPushButton("&Q", this);
    blackRock = new QPushButton("&R", this);
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
    whiteRock->setGeometry(572,200,50,50);
    whiteHorse->setGeometry(638,200,50,50);
    whiteBishop->setGeometry(704,200,50,50);
    whiteQueen->setGeometry(770,200,50,50);

    blackRock->setGeometry(572,350,50,50);
    blackHorse->setGeometry(638,350,50,50);
    blackBishop->setGeometry(704,350,50,50);
    blackQueen->setGeometry(770,350,50,50);

    whiteQueen->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");
    blackQueen->setStyleSheet("QPushButton {background-color: rgb(106, 228, 126);}");

    QObject::connect(restart, &QPushButton::released, this, &MainWindow::slotReboot);
    QObject::connect(ranking, &QPushButton::released, this, &MainWindow::slotShowRanking);
    QObject::connect(whiteRock, &QPushButton::released, this, &MainWindow::slotWhiteRock);
    QObject::connect(whiteHorse, &QPushButton::released, this, &MainWindow::slotWhiteHorse);
    QObject::connect(whiteBishop, &QPushButton::released, this, &MainWindow::slotWhiteBishop);
    QObject::connect(whiteQueen, &QPushButton::released, this, &MainWindow::slotWhiteQueen);
    QObject::connect(blackRock, &QPushButton::released, this, &MainWindow::slotBlackRock);
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
    chess->whiteKing = new Tile();
    chess->blackKing = new Tile();

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
            chess->tile[i][j] = new Tile(this);
            chess->tile[i][j]->tileColor=(i+j)%2;
            chess->tile[i][j]->piece=0;
            chess->tile[i][j]->row=i;
            chess->tile[i][j]->col=j;
            chess->tile[i][j]->tileNum=k++;
            chess->tile[i][j]->tileDisplay();
            chess->tile[i][j]->setGeometry(hor,ver,64,64);
            hor+=64;
        }
        ver+=64;
    }

    //black pawns
    for(j=0;j<8;j++)
    {
        chess->tile[1][j]->piece=1;
        chess->tile[1][j]->pieceColor=0;
        chess->tile[1][j]->display('P');
    }

    //white pawns
    for(j=0;j<8;j++)
    {
        chess->tile[6][j]->piece=1;
        chess->tile[6][j]->pieceColor=1;
        chess->tile[6][j]->display('P');
    }

    //white and black remaining elements
    for(j=0;j<8;j++)
    {
        chess->tile[0][j]->piece=1;
        chess->tile[0][j]->pieceColor=0;
        chess->tile[7][j]->piece=1;
        chess->tile[7][j]->pieceColor=1;
    }

    {
    chess->tile[0][0]->display('R');
    chess->tile[0][1]->display('H');
    chess->tile[0][2]->display('B');
    chess->tile[0][3]->display('Q');
    chess->tile[0][4]->display('K');
    chess->tile[0][5]->display('B');
    chess->tile[0][6]->display('H');
    chess->tile[0][7]->display('R');
    }


    {
    chess->tile[7][0]->display('R');
    chess->tile[7][1]->display('H');
    chess->tile[7][2]->display('B');
    chess->tile[7][3]->display('Q');
    chess->tile[7][4]->display('K');
    chess->tile[7][5]->display('B');
    chess->tile[7][6]->display('H');
    chess->tile[7][7]->display('R');
    }
    //remember Kings positions
    chess->blackKing->tileCopy(chess->tile[0][4]);
    chess->whiteKing->tileCopy(chess->tile[7][4]);
}

