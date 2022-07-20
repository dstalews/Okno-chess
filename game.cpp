#include "game.h"

Game::Game()
{
    count=0;
    turn=1;
    max=0;
    turnAll=1;
    whitePromotion = new Queen(1);
    blackPromotion = new Queen(0);
    ranking = new Ranking();
}

void Game::validate(Tile *temp)
{
    int retValue,i,j,c=++count;

    if(c==1)
    {
        if(temp->getPieceObject() && (temp->getPieceObject()->getPieceColor()==turn))
        {
            retValue=temp->getPieceObject()->validate(temp->getRow(),temp->getCol(),1);
            orange();
            if(retValue)
            {
                click1= new Tile();
                temp->setStyleSheet("QLabel {background-color: green;}");
                click1=temp;
            }
            else
            {
                count=0;
            }
        }
        else
        {
            count=0;
        }
    }

    else
    {

        if(temp->getTileNum()==click1->getTileNum())
        {
            click1->tileDisplay();
            disOrange();
            max=0;
            count=0;
        }

        for(i=0;i<max;i++)
        {
            if(temp->getTileNum()==exp[i])
            {
                specialMoves(temp);

                click1->tileSwap(temp);

                // if moving king then remeber new king position
                if (temp->getPieceObject()->getPieceName() == 'K')
                {
                    if (temp->getPieceObject()->getPieceColor())
                        whiteKing->tileCopy(temp);
                    else
                        blackKing->tileCopy(temp);
                }

                click1->display();
                temp->display();

                click1->tileDisplay();
                temp->tileDisplay();

                retValue = 0;
                for (i=0;i<=7;i++)
                {
                    for (j=0;j<=7;j++)
                    {
                        if (tile[i][j]->getPieceObject() && tile[i][j]->getPieceObject()->getPieceColor()!=temp->getPieceObject()->getPieceColor() && tile[i][j]->getPieceObject()->validate(i,j,1))
                        {
                            retValue = 1;
                            break;
                        }
                    }
                    if (retValue)
                        break;
                }

                disOrange();

                if(!retValue)
                {
                    label->setFrameStyle(QFrame::Panel);
                    label->setAlignment(Qt::AlignCenter);
                    label->setGeometry(572,420,250,50);
                    label->setStyleSheet("QLabel {background-color: yellow;}");
                    if (temp->getPieceObject()->getPieceColor())
                    {
                        label->setText("White player won");
                        if (player1 && player2)
                        {
                            player1->playerWin();
                            player2->playerLose();
                            ranking->updateRanking(player1->getPlayerName(),player1->getPlayerPoints());
                            ranking->updateRanking(player2->getPlayerName(),player2->getPlayerPoints());
                            ranking->saveRankingToFile();
                        }
                    }
                    else
                    {
                        label->setText("Black player won");
                        if (player1 && player2)
                        {
                            player2->playerWin();
                            player1->playerLose();
                            ranking->updateRanking(player1->getPlayerName(),player1->getPlayerPoints());
                            ranking->updateRanking(player2->getPlayerName(),player2->getPlayerPoints());
                            ranking->saveRankingToFile();
                        }
                    }
                }

                max=0;

                turn=(turn+1)%2;
                turnAll++;
                count=0;
            }

            else
                count=1;
        }
    }
}

void Game::disOrange()
{
    int i;

    for(i=0;i<max;i++)
        tile[exp[i]/8][exp[i]%8]->tileDisplay();

}

void Game::orange()
{
    int i;

    for(i=0;i<max;i++)
        tile[exp[i]/8][exp[i]%8]->setStyleSheet("QLabel {background-color: orange;}");
}

void Game::specialMoves(Tile *temp)
{
    if(temp->getRow()-1 >= 0 && tile[temp->getRow()-1][temp->getCol()]->getPieceObject() && temp->getPieceObject() == nullptr && tile[temp->getRow()-1][temp->getCol()]->getPieceObject()->getPieceName() == 'P' && temp->getCol() != click1->getCol() &&
         click1->getPieceObject() -> getPieceName() == 'P' && !click1->getPieceObject() -> getPieceColor())
    {
        tile[temp->getRow()-1][temp->getCol()] -> setPieceObject(nullptr);
        tile[temp->getRow()-1][temp->getCol()] -> display();
        tile[temp->getRow()-1][temp->getCol()] -> tileDisplay();
    }
    else if(temp->getRow()+1 <= 7 && tile[temp->getRow()+1][temp->getCol()]->getPieceObject() && temp->getPieceObject()==nullptr && tile[temp->getRow()+1][temp->getCol()]->getPieceObject()->getPieceName() == 'P' && temp->getCol() != click1->getCol() &&
             click1->getPieceObject() -> getPieceName() == 'P' && click1->getPieceObject() -> getPieceColor())
    {
        tile[temp->getRow()+1][temp->getCol()] -> setPieceObject(nullptr);
        tile[temp->getRow()+1][temp->getCol()] -> display();
        tile[temp->getRow()+1][temp->getCol()] -> tileDisplay();
    }
    else if(click1->getPieceObject() -> getPieceName() == 'K' && abs(temp->getCol()-click1->getCol())>1)
    {
        if(temp->getCol()>click1->getCol())
        {
            tile[temp->getRow()][7] -> tileSwap(tile[temp->getRow()][5]);
            tile[temp->getRow()][7] -> display();
            tile[temp->getRow()][7] -> tileDisplay();
            tile[temp->getRow()][5] -> display();
            tile[temp->getRow()][5] -> tileDisplay();
        }
        if(temp->getCol()<click1->getCol())
        {
            tile[temp->getRow()][0] -> tileSwap(tile[temp->getRow()][3]);
            tile[temp->getRow()][0] -> display();
            tile[temp->getRow()][0] -> tileDisplay();
            tile[temp->getRow()][3] -> display();
            tile[temp->getRow()][3] -> tileDisplay();
        }
    }
    else if (click1->getPieceObject()->getPieceName()=='P'&&click1->getPieceObject()->getPieceColor()&&click1->getRow()==1)
    {
        click1->setPieceObject(whitePromotion);
    }
    else if (click1->getPieceObject()->getPieceName()=='P'&&!click1->getPieceObject()->getPieceColor()&&click1->getRow()==6)
    {
        click1->setPieceObject(blackPromotion);
    }


    if((abs(temp->getRow()-click1->getRow())>1 && click1->getPieceObject()->getPieceName()=='P') || click1->getPieceObject()->getPieceName()=='K'||click1->getPieceObject()->getPieceName()=='R')
    {
        click1->getPieceObject()->setEn(turnAll);
    }
    else
    {
        click1->getPieceObject()->setEn(0);
    }


}

int Game::check(int r,int c, int color)
{

    int i, j, k, tmp = max;

    for (i=0;i<8;i++)
    {
        for (j=0;j<8;j++)
        {
            if (tile[i][j]->getPieceObject() && tile[i][j]->getPieceObject()->getPieceColor() != color && (i!=r || j !=c))
            {
                tile[i][j]->getPieceObject()->validate(i,j,0);
                for(k=tmp;k<max;k++)
                {
                    if (exp[k]/8 == r && exp[k]%8 == c)
                    {
                        max = tmp;
                        return 1;
                    }
                }
                max = tmp;
            }
        }
    }

    return 0;
}

Tile* Game::getTile(int i, int j)
{
    return tile[i][j];
}

void Game::newTile(int i, int j, QWidget* pParent)
{
    tile[i][j]= new Tile(pParent);
}

void Game::newExp(int tileNum)
{
    exp[max++]=tileNum;
}

int Game::getTurnAll()
{
    return turnAll;
}

void Game::resetVariables()
{
    count=0;
    turn=1;
    max=0;
    turnAll=1;
    whiteKing = new Tile();
    blackKing = new Tile();
    whitePromotion= new Queen(1);
    blackPromotion = new Queen(0);
}

Tile* Game::getWhiteKing()
{
    return whiteKing;
}

Tile* Game::getBlackKing()
{
    return blackKing;
}

void Game::newLabel(QWidget* pParent)
{
    label = new QLabel(pParent);
}

Ranking* Game::getRanks()
{
    return ranking;
}

void Game::setPromotion(char pieceName, int pieceColor)
{
    if (!pieceColor)
    {
        if (pieceName == 'Q')
            blackPromotion = new Queen(pieceColor);
        else if (pieceName == 'B')
            blackPromotion = new Bishop(pieceColor);
        else if (pieceName == 'H')
            blackPromotion = new Horse(pieceColor);
        else if (pieceName == 'R')
            blackPromotion = new Rook(pieceColor);
    }
    else if (pieceColor)
    {
        if (pieceName == 'Q')
            whitePromotion = new Queen(pieceColor);
        else if (pieceName == 'B')
            whitePromotion = new Bishop(pieceColor);
        else if (pieceName == 'H')
            whitePromotion = new Horse(pieceColor);
        else if (pieceName == 'R')
            whitePromotion = new Rook(pieceColor);
    }
}

Player* Game::getPlayer(int i)
{
    if (i==1)
        return player1;
    else
        return player2;
}

void Game::setPlayer(int i, std::string PlayerName, int points)
{
    if (i==1)
        player1 = new Player(PlayerName,points);
    else
        player2 = new Player(PlayerName,points);
}
