#include<iostream>
#include "clue.h"

using std::cout; 
using std::cin;


int main() {
    cout<<"What kind of game do you want to play\n";
    cout<<"Press 1 for hotseat or 2 for ranked game\n";

    clue no_one("janek smith");
    std::cout<<"checkChar('k'): "<<no_one.checkChar('k');
    std::cout<<"\ncheckChar('K'): "<<no_one.checkChar('K');
    std::cout<<"\ncheckChar('g'): "<<no_one.checkChar('g');


}