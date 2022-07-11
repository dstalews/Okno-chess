#include "player.h"

Player::Player(std::string playerName, int points)
{
    this->playerName = playerName;
    this->points = points;
}

void Player::playerWin()
{
    points++;
}

void Player::playerLose()
{
    points--;
}

std::string Player::getPlayerName()
{
    return playerName;
}

int Player::getPlayerPoints()
{
    return points;
}
