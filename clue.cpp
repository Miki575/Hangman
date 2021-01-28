#include "clue.h"


clue::clue(std::string org_clue) {

    m_org_clue = org_clue;
    m_len = m_org_clue.length();
    this->hide(); 
}  

clue::~clue() {

}

void clue::hide() {

    m_covered_clue = m_org_clue;

    for (int i = 0; i < len; i++) {

        if (m_covered_clue[i] == ' ') 
            continue;
        else
            m_covered_clue[i] = '*';
    }
    
} 

bool clue::checkChar(char guess) {

    bool found = false;
    guess = tolower(guess);
    for (int i = 0; i < len; i++) {

        if (m_org_clue[i] == guess) {
            m_covered_clue[i] = guess;
            found = true;
        }
        else {
            continue;
        }
    }

    return found;
} 