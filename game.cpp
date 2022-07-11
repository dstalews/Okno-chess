#include "game.h"

Game::Game()
{
    count=0;
    turn=1;
    max=0;
    turnAll=1;
    whitePromotion = 'Q';
    blackPromotion = 'Q';
    valid = new Validation();
    ranking = new Ranking();
}

void Game::validate(Tile *temp, int c)
{
    int retValue,i,j;

    if(c==1)
    {
        if(temp->piece && (temp->pieceColor==turn))
        {
            retValue=valid->chooser(temp,1);

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
                if (temp->pieceName == 'K')
                {
                    if (temp->pieceColor)
                        whiteKing->tileCopy(temp);
                    else
                        blackKing->tileCopy(temp);
                }

                click1->display(click1->pieceName);
                temp->display(click1->pieceName);

                click1->tileDisplay();
                temp->tileDisplay();

                retValue = 0;
                for (i=0;i<=7;i++)
                {
                    for (j=0;j<=7;j++)
                    {
                        if (tile[i][j]->piece==1 && tile[i][j]->pieceColor!=temp->pieceColor && valid->chooser(tile[i][j],1))
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
                    if (temp->pieceColor)
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
    if(temp->row-1 >= 0 && tile[temp->row-1][temp->col]->pieceName == 'P' && tile[temp->row-1][temp->col]->piece && temp->col != click1->col &&
         click1 -> pieceName == 'P' && !click1 -> pieceColor && !temp->piece)
    {
        tile[temp->row-1][temp->col] -> piece = 0;
        tile[temp->row-1][temp->col] -> display(tile[temp->row-1][temp->col]->pieceName);
        tile[temp->row-1][temp->col] -> tileDisplay();
    }
    else if(temp->row+1 <= 7 && tile[temp->row+1][temp->col]->pieceName == 'P' && tile[temp->row+1][temp->col]->piece && temp->col != click1->col &&
             click1 -> pieceName == 'P' && click1 -> pieceColor && !temp->piece)
    {
        tile[temp->row+1][temp->col] -> piece = 0;
        tile[temp->row+1][temp->col] -> display(tile[temp->row+1][temp->col]->pieceName);
        tile[temp->row+1][temp->col] -> tileDisplay();
    }
    else if(click1 -> pieceName == 'K' && abs(temp->col-click1->col)>1)
    {
        if(temp->col>click1->col)
        {
            tile[temp->row][7] -> piece = 0;
            tile[temp->row][7] -> display(tile[temp->row][7]->pieceName);
            tile[temp->row][7] -> tileDisplay();
            tile[temp->row][5] -> piece = 1;
            tile[temp->row][5] -> pieceColor=click1->pieceColor;
            tile[temp->row][5] -> pieceName='R';
            tile[temp->row][5] -> display('R');
            tile[temp->row][5] -> tileDisplay();
        }
        if(temp->col<click1->col)
        {
            tile[temp->row][0] -> piece = 0;
            tile[temp->row][0] -> display(tile[temp->row][7]->pieceName);
            tile[temp->row][0] -> tileDisplay();
            tile[temp->row][3] -> piece = 1;
            tile[temp->row][3] -> pieceColor=click1->pieceColor;
            tile[temp->row][3] -> pieceName='R';
            tile[temp->row][3] -> display('R');
            tile[temp->row][3] -> tileDisplay();
        }
    }
    else if (click1 -> pieceName == 'P' && click1 -> pieceColor && click1->row == 1)
    {
        click1 -> pieceName = whitePromotion;
    }
    else if (click1 -> pieceName == 'P' && !click1 -> pieceColor && click1->row == 6)
    {
        click1 -> pieceName = blackPromotion;
    }

    if((abs(temp->row-click1->row)>1 && click1 -> pieceName == 'P') || click1 -> pieceName == 'K' || click1 -> pieceName == 'R')
    {
        temp -> en = turnAll;
    }
    else
    {
        temp -> en = 0;
    }

}
