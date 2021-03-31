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

    for (int i = 0; i < m_len; i++) {

        if (m_covered_clue[i] == ' ') 
            continue;
        else
            m_covered_clue[i] = '*';
    }
    
} 

rc clue::checkChar(char guess) {

    rc found = no;
    guess = tolower(guess);
    for (int i = 0; i < m_len; i++) {

        if (m_org_clue[i] == guess) {
            m_covered_clue[i] = guess;
            found = (m_covered_clue == m_org_clue) ? done : yes;
        }
        else {
            continue;
        }
    }

    return found;
} 

void clue::showClue() const {
    
    usleep(500);
    system("clear");
    std::cout<<"\t\t"<<m_covered_clue<<"\n\n";

}