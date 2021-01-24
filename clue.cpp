#include "clue.h"


clue::clue(std::string m_org_clue) {

    org_clue = m_org_clue;
    len = org_clue.length();
    this->hide(); 
}  

clue::~clue() {

}

void clue::hide() {

    covered_clue = org_clue;

    for (int i = 0; i < len; i++) {

        if (covered_clue[i] == ' ') 
            continue;
        else
            covered_clue[i] = '*';
    }
    
} 

bool clue::checkChar(char guess) {

    guess = tolower(guess);
    for (int i = 0; i < len; i++) {

        if (org_clue[i] == guess) {
            covered_clue[i] = guess;
            return true;
        }
        else {
            continue;
        }
    }

    return false;
} 