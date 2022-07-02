#ifndef PLAYER_H_
#define PLAYER_H_

#include<string>
#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>

#include "rankingDB.h"
#include "clue.h"

class player {
    private:
    std::string m_name;
    long int m_points;
    void gameplay(const clueDB &clueBase);
    bool addPlayer(std::string name);

    public:
    player();
    player(std::string name, long points);
    ~player();
    std::string getName() const {return m_name;}
    long getPoints() const {return m_points;}
    short ranked_game(const clueDB &clueBase); //returns gained points
    void hotseat_game();    
};

#endif //PLAYER_H_