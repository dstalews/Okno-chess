#ifndef GAME_H
#define GAME_H
#include "tile.h"
#include "ranking.h"
#include "player.h"
#include "piece.h"
#include "bishop.h"
#include "horse.h"
#include "king.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"

class Game
{
private:
    int count, turn, exp[60], max, turnAll;
    Tile *tile[8][8] = { { NULL } }, *click1, *blackKing, *whiteKing;
    QLabel *label;
    Piece *whitePromotion, *blackPromotion;
    Ranking *ranking;
    Player *player1, *player2;
public:
    Game();
    void validate(Tile *temp);
    void disOrange();
    void orange();
    void specialMoves(Tile *temp);
    int check(int r,int c, int color);
    Tile* getTile(int i, int j);
    void newTile(int i, int j, QWidget* pParent);
    void newExp(int tileNum);
    int getTurnAll();
    void resetVariables();
    Tile* getWhiteKing();
    Tile* getBlackKing();
    void newLabel(QWidget* pParent);
    void setPromotion(char pieceName, int pieceColor);
    Ranking* getRanks();
    Player* getPlayer(int i);
    void setPlayer(int i, std::string PlayerName, int points);
};

#endif // GAME_H
