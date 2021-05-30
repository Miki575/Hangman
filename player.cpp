#include "player.h"


player::player() {
    std::cout<<"Enter your nick: ";
    getline(std::cin, m_name);
    m_points = 0;
    std::cout<<"You've been added to ranking\n";
    std::cout<<"Enjoy!\n";
}

player::player(std::string name, long points) {
    m_name = name;
    m_points = points;
}

player::~player() {
    
}

short player::ranked_game() {
    

    return 0;
}

void player::hotseat_game() {
    
}

void player::gameplay(const clueDB &clueBase)
{
    using std::cout;
    using std::cin;

    /*
    1. Inicjalizacja obiektu typu clue- wylosowanym haslem z tabeli SQL 
    2. Przygowanie hasla- zasloniecie * i zmiania wielkosic if necessary
    3. Zgadywanie hasla
        a) wypisanie uzytych liter
        b) sprawdzenie czy wpisana litera jest w hasle i ewentualna podmiana
        c) aktualizacja liczby prob
    [4.] przekazanie liczby punktow 
    */

    char guess;
    std::vector<char> used;
    rc guess_status;   
    //preparation
    clue current(clueBase.randomClueDB());
    short attempts = current.getSize();

    cout<<"Here we go!\n";
    do 
    {
        current.showClue();
        cout<<"Enter your guess: ";
        cin>>guess;
        tolower(guess);
        if(std::find(used.begin(), used.end(), guess) != used.end()) { //check if this letter wasn't used before
            cout<<"You are repeating yourself!\n";
            continue;
        } 
        else {
            used.push_back(guess);
            guess_status = current.checkChar(guess);
            if(guess_status == yes) {
                cout<<"Well done!\n";
            } else if(guess_status == no){
                cout<<"No way, Jose!\n"; 
                attempts--; 
                if(attempts == 0) {
                    cout<<"It was your last try \n";
                    cout<<"GAME OVER\n";
                    break;
                }
            } else //gues_status == done, clue was guessed
                cout<<"You score "<<attempts<<" point"<<(attempts > 1) ? "s\n" : "\n";
        }
    }while(guess_status != done);

    m_points += attempts;

}