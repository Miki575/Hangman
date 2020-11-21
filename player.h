#ifndef PLAYER_H_
#define PLAYER_H_

#include<string>

class player {
    private:
    std::string name;
    long int points;

    public:
    player();
    player(std::string m_name, long m_points);
    ~player();
        
}

#endif //PLAYER_H_