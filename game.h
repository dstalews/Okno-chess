#ifndef GAME_H
#define GAME_H
#include "tile.h"
#include "ranking.h"
#include "player.h"

class Game
{
public:
    int count, turn, exp[60], max, turnAll;
    Tile *click1, *blackKing, *whiteKing, *tile[8][8] = { { NULL } };
    QLabel *label;
    char whitePromotion, blackPromotion;
    Ranking *ranking;
    Player *player1, *player2;
    Game();
    void validate(Tile *temp, int c);
    void disOrange();
    void orange();
    void specialMoves(Tile *temp);
    int check(int r,int c, int color);

};

#endif // GAME_H
