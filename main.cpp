#include "hangman.h" 

player current;

int main()
{
    bubble_sort();
    type_of_game current_game=show_menu();
    if(current_game==ranking)
        ranked();
    else hot_seat();
    std::cin.get();
    std::cin.get();
    return 0;
}
