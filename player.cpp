#include "player.h"
#include "rankingDB.h"


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

short int gameplay(const string pass, string covered, short spaces)
{
    /*
    1. Inicjalizacja obiektu typu clue- wylosowanym haslem z tabeli SQL 
    2. Przygowanie hasla- zasloniecie * i zmiania wielkosic if necessary
    3. Zgadywanie hasla
        a) wypisanie uzytych liter
        b) sprawdzenie czy wpisana litera jest w hasle i ewentualna podmiana
        c) aktualizacja liczby prob
    [4.] przekazanie liczby punktow 
    */




    using std::cout;
    using std::cin;

    short letters=pass.size();
    short attempts=letters-spaces;//tyle prob ile liter
    char guess;
    char used[30]= {0}; //tablica na zuzyte litery
    int j=0;
    cout<<"Zaczynamy. Powodzenia!\n";
    while(covered != pass)
    {
        cout<<"Pozostalo Ci "<<attempts<<" prob\t\tUzyte litery: ";
        for(int i=0; i<j && j>0; i++)//wypisywanie zuzytych liter
            cout<<used[i]<<", ";
        cout<<"\n\t"<<covered<<std::endl;
        cout<<"Podaj litere: ";
        cin>>guess;
        used[j]=guess;
        int k=0;
        for(int i=0; i<letters; i++)//sprawdzanie czy dana litera jest w hasle i ewentualna zamiana
        {
            if(pass[i]==guess)
                covered[i]=guess;
            else if(pass[i]==(char)(guess+32))
                covered[i]=(char)(guess+32);
            else
            {
                k++;
                continue;
            }
        }
        if(k==letters)//prawda jesli zadna z liter w hasle nie pokrywa sie ze strzalem, czyli jesli ktos nie trafil
        {
            attempts--;//odjecie jednej proby, bo nie trafil
            cout<<"Nie trafiles!\n";
            if(attempts==0)//jak nie ma juz zyc to game over
                break;
        }
        else
            cout<<"Brawo brawo brawissimo!\n";
        j++;
        usleep(500);
        system("clear");
    }
    return attempts;
}