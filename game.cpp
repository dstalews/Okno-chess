#include "game.h"
#include "queen.h"

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

void Game::validate(Tile *temp, int c)
{
    int retValue,i,j;

    if(c==1)
    {
        if(temp->pieceObject && (temp->pieceObject->getPieceColor()==turn))
        {
            retValue=temp->pieceObject->validate(temp->row,temp->col,1);
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

        if(temp->tileNum==click1->tileNum)
        {
            click1->tileDisplay();
            disOrange();
            max=0;
            count=0;
        }

        for(i=0;i<max;i++)
        {
            if(temp->tileNum==exp[i])
            {
                specialMoves(temp);

                click1->tileSwap(temp);

                // if moving king then remeber new king position
                if (temp->pieceObject->getPieceName() == 'K')
                {
                    if (temp->pieceObject->getPieceColor())
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
                        if (tile[i][j]->pieceObject && tile[i][j]->pieceObject->getPieceColor()!=temp->pieceObject->getPieceColor() && tile[i][j]->pieceObject->validate(i,j,1))
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
                    if (temp->pieceObject->getPieceColor())
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
    if(tile[temp->row-1][temp->col]->pieceObject && temp->pieceObject == nullptr && temp->row-1 >= 0 && tile[temp->row-1][temp->col]->pieceObject->getPieceName() == 'P' && temp->col != click1->col &&
         click1->pieceObject -> getPieceName() == 'P' && !click1->pieceObject -> getPieceColor())
    {
        tile[temp->row-1][temp->col] -> pieceObject = nullptr;
        tile[temp->row-1][temp->col] -> display();
        tile[temp->row-1][temp->col] -> tileDisplay();
    }
    else if(tile[temp->row+1][temp->col]->pieceObject && temp->pieceObject==nullptr && temp->row+1 <= 7 && tile[temp->row+1][temp->col]->pieceObject->getPieceName() == 'P' && temp->col != click1->col &&
             click1->pieceObject -> getPieceName() == 'P' && click1->pieceObject -> getPieceColor())
    {
        tile[temp->row+1][temp->col] -> pieceObject = nullptr;
        tile[temp->row+1][temp->col] -> display();
        tile[temp->row+1][temp->col] -> tileDisplay();
    }
    else if(click1->pieceObject -> getPieceName() == 'K' && abs(temp->col-click1->col)>1)
    {
        if(temp->col>click1->col)
        {
            tile[temp->row][7] -> tileSwap(tile[temp->row][5]);
            tile[temp->row][7] -> display();
            tile[temp->row][7] -> tileDisplay();
            tile[temp->row][5] -> display();
            tile[temp->row][5] -> tileDisplay();
        }
        if(temp->col<click1->col)
        {
            tile[temp->row][0] -> tileSwap(tile[temp->row][3]);
            tile[temp->row][0] -> display();
            tile[temp->row][0] -> tileDisplay();
            tile[temp->row][3] -> display();
            tile[temp->row][3] -> tileDisplay();
        }
    }
    else if (click1->pieceObject->getPieceName()=='P'&&click1->pieceObject->getPieceColor()&&click1->row==1)
    {
        click1->pieceObject = whitePromotion;
    }
    else if (click1->pieceObject->getPieceName()=='P'&&!click1->pieceObject->getPieceColor()&&click1->row==6)
    {
        click1->pieceObject = blackPromotion;
    }
    if (temp->pieceObject)
    {
        if((abs(temp->row-click1->row)>1 && click1->pieceObject->getPieceName()=='P') || click1->pieceObject->getPieceName()=='K'||click1->pieceObject->getPieceName()=='R')
        {
            temp->pieceObject->setEn(turnAll);
        }
        else
        {
            temp->pieceObject->setEn(0);
        }
    }

}

int Game::check(int r,int c, int color)
{

    int i, j, k, tmp = max;

    for (i=0;i<8;i++)
    {
        for (j=0;j<8;j++)
        {
            if (tile[i][j]->pieceObject && tile[i][j]->pieceObject->getPieceColor() != color && (i!=r || j !=c))
            {
                tile[i][j]->pieceObject->validate(i,j,0);
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
