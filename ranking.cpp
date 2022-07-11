#include "ranking.h"
using namespace std;

Ranking::Ranking()
{
    string pos, playerName, points;
    ifstream myfile;
    myfile.open("ranking.txt");
    ranking_size = 0;
    if ( myfile.is_open() )
    {
        while ( myfile >> pos  && ranking_size < 20)
        {
            myfile >> playerName;
            myfile >> points;
            playerName.erase(playerName.end()-1);
            ranking_vector.push_back (make_pair(stoi(points), playerName));
            ranking_size++;
        }
    }
    sort(ranking_vector.rbegin(), ranking_vector.rend());
    myfile.close();
}

int Ranking::getPlayerPoints(string playerName)
{
    for (int i=0; i<ranking_size;i++)
    {
        if (playerName == ranking_vector[i].second)
            return ranking_vector[i].first;
    }
    return 100;
}

void Ranking::updateRanking(string playerName, int points)
{

    for (int i=0; i<ranking_size;i++)
    {
        if (playerName == ranking_vector[i].second)
        {
            ranking_vector[i].first = points;
            sort(ranking_vector.rbegin(), ranking_vector.rend());
            return;
        }
    }
    ranking_vector.push_back ( make_pair(points, playerName));
    sort(ranking_vector.rbegin(), ranking_vector.rend());
    ranking_size++;
}

void Ranking::saveRankingToFile()
{

    string text = getRanking();
    fstream outfile;

    string filename("ranking.txt");
    FILE *o_file = fopen(filename.c_str(), "w+");
    if (o_file){
        fwrite(text.c_str(), 1, text.size(), o_file);
    }
}

string Ranking::getRanking()
{
    if (ranking_size == 0)
        return "";
    string view;
    int pos = 1, last_points = ranking_vector[0].first;
    for (int i=0; i<ranking_size;i++)
    {
        if (last_points != ranking_vector[i].first)
            pos++;
        view += to_string(pos) +". "+ranking_vector[i].second+": "+ to_string(ranking_vector[i].first)+"\n";
        last_points = ranking_vector[i].first;
    }
    return view;
}
