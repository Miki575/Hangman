#ifndef PLAYER_H_
#define PLAYER_H_

#include<string>
#include<iostream>

class player {
    private:
    std::string m_name;
    long int m_points;
    short int gameplay(const std::string pass, std::string covered, short spaces);


    public:
    player();
    player(std::string name, long points);
    ~player();
    std::string getName() const {return m_name;}
    long getPoints() const {return m_points; }
    short ranked_game(); //returns gained points
    void hotseat_game();    
};

#endif //PLAYER_H_