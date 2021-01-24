#ifndef CLUE_H_
#define CLUE_H_

#include<string>

class clue {
    private:
    std::string org_clue;                               //has to be in low letters
    std::string covered_clue;
    short len;
    void hide();                                        //replace letters with *



    public:
    clue(std::string m_org_clue);                       //will be initialized with clue from SQL table
    ~clue();
    bool checkChar(char guess);                         //check if letter occurs in clue and replace it

};

#endif //CLUE_H_