#ifndef PLAYER_H_
#define PLAYER_H_

#include<string>
#include<iostream>

class player {
    private:
    std::string name;
    long int points;
    short int gameplay(const std::string pass, std::string covered, short spaces);


    public:
    player();
    player(std::string m_name, long m_points);
    ~player();
    std::string getName() const {return name;}
    long getPoints() const {return points; }
    short ranked_game(); //returns gained points
    void hotseat_game();    
};

#endif //PLAYER_H_