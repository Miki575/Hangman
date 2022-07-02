## Table of content
1. [Goal of this project](#Goal)
2. [How to start](#start)
    - [Compilation](#compile)        
    - [Xampp](#Xampp)
3. [Purpose of main classes](#classes)
4. [Useful links](#links) 
## Goal of this project <a name="Goal"></a>
Main goal of this project is to create simple game application with Qt interface and possibility to play via internal network.

## How to start <a name="start"></a>
### Compilation <a name="compile"></a>
`make all`-creates executable file "HangmanGame"  
`make clean`- deletes all object files created in the previous step
### Xampp- db on localhost <a name="Xampp"></a>
#### How to start?
`/opt/lampp/manager-linux-x64.run` - start graphical interface.
Power-on Apache server and SQL server. Have a look at your DB-> [localhost/phpmyadmin](http://localhost/phpmyadmin/)  
#### Test SQL querries
To test your SQL querries you can use php scripts: `dbconnect.php`, `index.php` and `zapytania.txt` with SQL querries. All of these three files in order to work with Xampp should be located in `/opt/lampp/htdocs/` (use `syncXampp` command). Querry output you can view in the browser at [localhost/QuerryTest/](http://localhost/QuerryTest/)
## Purpose of main classes <a name="classes"></a>
### DB
Base class with all necessary members to receive access to SQL tables in DB.
#### rankingDB
Subclass with all necessary methods to manage players in data base
#### clueDB
Subclass with all necessary methods to manage clues in data base
### clue
Class/Data type representing clue during the game
### player
Class/Data type representing player currently playing
## Useful links <a name="links"></a>
* [github](https://github.com/Miki575/Hangman)
* [trello](https://trello.com/b/YoOQn3bZ/hangman)
* [SQLdocs](https://dev.mysql.com/doc/connector-cpp/8.0/en/connector-cpp-introduction.html)
* [SQLExamples](https://archive.fo/TeGBj)