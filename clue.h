#ifndef CLUE_H_
#define CLUE_H_

#include<string>
#include<unistd.h>
enum rc {yes, no, done};

class clue {
    private:
    std::string m_org_clue;                               //has to be in low letters
    std::string m_covered_clue;
    short m_len;
    void hide();                                        //replace letters with *



    public:
    clue(std::string org_clue);                       //will be initialized with clue from SQL table
    ~clue();
    rc checkChar(char guess);                         //check if letter occurs in clue and replace it
    short getSize() {return m_len;}
    void showClue() const;

};

#endif //CLUE_H_