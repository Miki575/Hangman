#ifndef rankingDB_H_
#define rankingDB_H_

#include <stdlib.h>
#include <iostream>
#include <iomanip>

//#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>


class DB {
    private:
    std::string m_SQLserver;
    std::string m_SQLuser;
    std::string m_SQLpass;
    sql::Driver *m_driver;
    //bool remplayerDB() const;

    protected:
    sql::Connection *m_con;

    public:
    DB(std::string SQLserver, std::string SQLuser, std::string SQLpass, std::string SQLschema);
    ~DB();
};




class rankingDB : public DB {
    private:
    std::string m_SQLtable;
    bool addplayerDB(std::string m_nick) const; //add new player to DB

    public:
    rankingDB(std::string SQLserver = "tcp://localhost:3306", std::string SQLuser = "root", 
    std::string SQLpass = "", std::string SQLschema = "Hangman", std::string SQLtable = "users");
    ~rankingDB();
    bool updateDB(const std::string m_nick, const long m_points) const;
    bool listplayersDB(const std::string m_nick = "none") const;  //list all players
    short CheckPlayerDB(const std::string m_nick) const; //check player existance in DB, This method could be considered to be implemented in class player???
};





class clueDB : public DB {
    private:
    std::string m_SQLtable;

    public:
    clueDB(const std::string & SQLserver = "tcp://localhost:3306", const std::string & SQLuser = "root", 
    const std::string & SQLpass = "", const std::string & SQLschema = "Hangman", const std::string & SQLtable = "clues");
    ~clueDB();
    std::string randomClueDB() const;
    bool addClueDB(const std::string & candidate_clue);//add candidate_clue for futher verification, only clues from hotseat
    bool remClueDB(const std::string & candidate_clue);//remove candidate_clue if valid == -3
    bool verClueDB();//ask user to verify candidate_clue and in/decrease valid

};

#endif  //rankingDB_H_