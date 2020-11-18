#ifndef HANGMAN_H_
#define HANGMAN_H_

#include<string>
#include<cstdlib>
#include<string>
#include<fstream>
#include<cctype>
#include<unistd.h>
#include<iostream>
#include<cstdlib>
#include<time.h>

enum type_of_game {ranking,hotseat};
using std::string;

struct player
{
    string nick;
    int points;
    int position;//ktora linijka w pliku
};

type_of_game show_menu();
short to_lower(string & pass);
string cover(const string pass);
void ranked();
void hot_seat();
short int gameplay(const string pass, string covered, short spaces);
void bubble_sort();//sortuje ranking
void update();//aktualizuje punkty gracza
int Search(const char *nick);//zwraca nr linijki na ktorej jest nazwa danego gracza


#endif // hangman_H_
