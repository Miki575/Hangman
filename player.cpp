#include "player.h"


player::player() {
    std::cout<<"Enter your nick: ";
    getline(std::cin, name);
    points = 0;
    std::cout<<"You've been added to ranking\n";
    std::cout<<"Enjoy!\n";
}

player::player(std::string m_name, long m_points) {
    name = m_name;
    points = m_points;
}

short player::ranked_game() {

}

void player::hotseat_game() {

}