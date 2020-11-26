#ifndef PLAYER_H_
#define PLAYER_H_

#include<string>
#include<iostream>

class player {
    private:
    std::string name;
    long int points;

    public:
    player();
    player(std::string m_name, long m_points);
    ~player();
    short ranked_game(); //returns gained points
    void hotseat_game();    
};

#endif //PLAYER_H_