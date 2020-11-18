#include"hangman.h"

extern player current;

type_of_game show_menu()
{
    using namespace std;

    char choice;
    cout<<"Wybierz tryb gry: \n"
        <<"1.Gra rankingowa\t2.Hot seat- 1vs1\n";
    cout<<"Wybierz nr 1 lub 2 ";
    cin>>choice;
    while(!(choice=='1' || choice=='2'))//wczytuj znaki, dopoki nie zostanie podane 1 lub 2
        cin>>choice;
    system("clear");
    if(choice=='1')//Gra rankingowa
    {
        string temp;
        fstream file;
        cin.get();
        cout<<"Podaj swoj nick: ";
        getline(cin, current.nick);
        file.open("users.txt", ios::in);//otwieranie pliku z nazwami graczy i ich punktami, do odczytu
        if(!file.is_open())//sprawdzenie poprawnosci otwarcia pliku
        {
            cout<<"Wystapil blad, program zostanie zakonczony\n";
            exit(EXIT_FAILURE);
        }
        bool i=false;
        int line=1;
        getline(file, temp);
        while(file.good())//dopoki dobre dane i nie eof
        {
            if(temp==current.nick)//sprawdzenie, czy wpisana nazwa gracza, wystepuje juz na liscie
            {
                file>>current.points;
                current.position=line;
                file.get();
                i=true;
                break;
            }
            getline(file, temp);//wczytanie linijki z nickiem- bardziej przwiniecie, zeby pojsc do kolejnej nazwy
            getline(file, temp);//przewiniecie zdobytych punktow
            line=line+2;//
        }
        if(i)
        {
            cout<<"Jestes juz na naszej liscie, "<<current.nick<<" i masz "<<current.points<<" punktow.\n";
            cout<<"Twoja linijka: "<<current.position<<endl;
        }
        else
        {
            cout<<"Jestes nowy, zaraz dopiszemy Cie do listy rankingowej\n";
            file.close();//zakonczenie pracy ze zmienna plikowa sluzaca do odczytu
            file.clear();//wyczyszczenie strumienia
            file.open("users.txt", ios_base::out | ios_base::app);//przypisanie zmiennej plikowej pliku w trybie zapisu i dopisywania
            if(!file.is_open())
            {
                cout<<"Wystapil blad, program zostanie zakonczony\n";
                exit(EXIT_FAILURE);
            }
            file<<current.nick<<endl;
            file<<"0"<<endl;
            current.position=line;
            file.close();
            cout<<"Twoja linijka: "<<current.position<<endl;
        }
        return ranking;
    }
    else //1vs1
        return hotseat;

}

short to_lower(string & pass)//zmienianie liter w hasle na tylko male litery
{
    short spacje=0;
    short litery=pass.size();
    for(int i=0; i<litery; i++)
    {
        if(pass[i]==' ')
        {
            spacje++;
            continue;
        }
        else if(isalpha(pass[i]))
        {
            if((int)pass[i]<=90)
            {
                pass[i]=(char)(pass[i]+32);
                continue;
            }
            else
                continue;
        }
    }
    return spacje;
}

string cover(const string pass)//zakrywanie hasla gwiazdkami
{
    string covered=pass;
    short letters=pass.size();

    for (int i=0; i<letters; i++)
    {
        if(covered[i]==' ')
            continue;
        else
            covered[i]='*';
    }
    return covered;
}

void bubble_sort() //tu powinna zostać przekazane jakies parametry, bo póki co f-cja dziala tylko dla jednego pliku tekstowego)
{
    using namespace std;

    string temp;
    int lines=0;
    string *nicks;
    int *points;
    fstream file;
    file.open("users.txt", ios_base::in | ios_base::out);
    if(!file.is_open())
    {
        cout<<"Wystapil blad, program zostanie zakonczony\n";
        exit(EXIT_FAILURE);
    }
    while(getline(file, temp))//zliczanie linijek w pliku
        lines++;
    int records = lines/2;
    cout<<"Linie: "<<records<<endl;
    nicks=new string [records];//tablica nickow
    points=new int [records];//tablica punktacji
    file.clear();
    file.seekg(0);
    for (int i=0; i<records; i++)//pobieranie danych do tablicy, ktora zaraz bedzie posortowana
    {
        getline(file,nicks[i]);
        file>>points[i];
        file.get();
    }

    //Sortowanie tablic.
    for(int i=0; i<records; i++)
    {
        int temp_swap;
            for(int j=0; j<records-1; j++)
        {
            if(points[j] < points[j+1])
            {
                temp_swap = points[j+1];
                points[j+1] = points[j];
                points[j] = temp_swap;
                temp = nicks[j+1];
                nicks[j+1] = nicks[j];
                nicks[j] = temp_swap;
            }
        }
    }
    cout<<"Prezentacja zawodnikow: \n";//do sprawdzenia czy dziala.
    for(int i=0; i<records; i++)
    {
        cout<<i+1<<": "<<nicks[i]<<", punkty: "<<points[i]<<endl;
    }

    //Zapis spowrotem do plku w nalezytej kolejnosci.
    file.clear();
    file.seekg(0);
    for(int i=0; i<records; i++)
    {
        file<<nicks[i]<<endl;
        file<<points[i];
        (i == records - 1) ? file<<"" : file<<endl;//jesli ostatni gracz zostal wczytany to nie dodawaj "\n"
    }


    file.close();
    delete [] nicks;
    delete [] points;
}

short int gameplay(const string pass, string covered, short spaces)
{
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

void ranked()
{
    using std::cout;
    //system("clear");

    //1. Losowanie hasla z pliku
    std::string temp;
    std::ifstream file;
    file.open("passes.txt", std::ios::in);
    if(!file.is_open())
    {
        cout<<"Wystapil blad, program zostanie zakonczony\n";
        exit(EXIT_FAILURE);
    }
    int lines=0;
    while(getline(file, temp))//zliczanie linijek w pliku
        lines++;

    srand(time(NULL));
    short position=rand()%lines+1;//zainicjowana wartoscia wylosowana z generatora

    std::string haslo;
    file.clear();
    file.seekg(0);//ustawienie wskaznika pliku na poczatek
    for(int i=1; i<position; i++)//ustawianie "kursora" na wylosowana linie z haslem
        getline(file, haslo);//przewijanie, zmienna haslo w roli tymczasowego bufora na dane
    getline(file, haslo);//wczytanie wlasciwej linijki z haslem

    //2. Przygotowanie hasla, czyli f-cje:to_lower, cover
    short spacje=to_lower(haslo);
    std::string zakryte=cover(haslo);

    //3. F-cja gameplay
    int punkty=gameplay(haslo, zakryte, spacje);
    //4. Wypisanie zdobytych punktow, wszystkich punktow i miejsce w rankingu- jeszcze nie skonczone.
    if(punkty>0)
        cout<<"Hurra!\a\n"
            <<"Haslo to: \""<<haslo<<"\"\n";
    else
        cout<<"Niestety nie udalo sie. \n\t\t\t\t***GAME OVER***\n";
    current.points+=punkty;
    cout<<current.points<<std::endl;

    file.close();
}

void hot_seat()
{
    using std::cout;
    using std::cin;
    system("clear");
    cin.get();
    cout<<"Podaj haslo ktore Twoj przeciwnik ma zgadnac: ";
    string haslo;
    getline(cin, haslo);//wcytanie hasla podanego przez przeciwnika
    system("clear");
    short spacje=to_lower(haslo);
    string zakryte=cover(haslo);
    int punkty=gameplay(haslo, zakryte, spacje);
    if(punkty>0)
        cout<<"Hurra!\a\n"
            <<"Haslo to: \""<<haslo<<"\"\n";
    else
        cout<<"Niestety nie udalo sie. \n\t\t\t\t***GAME OVER***\n";
}
