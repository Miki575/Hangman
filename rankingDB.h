#ifndef rankingDB_H_
#define rankingDB_H_

#include <stdlib.h>
#include <iostream>
#include <iomanip>

//#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

#include "player.h"

class rankingDB {
    private:
    std::string m_SQLserver;
    std::string m_SQLuser;
    std::string m_SQLpass;

    sql::Driver *m_driver;
    sql::Connection *m_con;

    bool addplayerDB(std::string m_nick) const; //add new player to DB
    //bool remplayerDB() const;
    bool connectDB();                           //connect to SQL DB
    

    public:
    rankingDB();
    rankingDB(std::string SQLserver, std::string SQLuser, std::string SQLpass);
    ~rankingDB();
    bool updateDB(const std::string m_nick, const long m_points) const;
    bool listplayersDB(const std::string m_nick = "none") const;  //list all players
    short CheckPlayerDB(const std::string m_nick) const; //check player existance in DB
};

#endif  //rankingDB_H_