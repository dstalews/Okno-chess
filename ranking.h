#ifndef RANKING_H
#define RANKING_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>


class Ranking
{
    std::vector<std::pair<int, std::string>> ranking_vector;
    int ranking_size;
public:
    Ranking();
    int getPlayerPoints(std::string playerName);
    void updateRanking(std::string playerName, int points);
    void saveRankingToFile();
    std::string getRanking();
};

#endif // RANKING_H
