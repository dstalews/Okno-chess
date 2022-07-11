#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
    int points;
    std::string playerName;
public:
    Player(std::string playerName, int points);
    void playerWin();
    void playerLose();
    std::string getPlayerName();
    int getPlayerPoints();
};

#endif // PLAYER_H
