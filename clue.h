#ifndef CLUE_H_
#define CLUE_H_

#include<string>

class clue {
    private:
    std::string org_clue;
    std::string covered_clue;
    void hide();                                        //replace letters with *



    public:
    clue(std::string m_org_clue);                       //will be initialized with clue from SQL table
    ~clue();
    bool checkChar(char guess);                         //check if letter occurs in clue and replace it

};

#endif //CLUE_H_