#ifndef rankingDB_H_
#define rankingDB_H_

#include <stdlib.h>
#include <iostream>

//#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

#include "player.h"

class rankingDB {
    private:
    std::string SQLserver;
    std::string SQLuser;
    std::string SQLpass;

    sql::Driver *driver;
    sql::Connection *con;

    bool addplayerDB() const;
    bool remplayerDB() const;
    bool connectDB();
    

    public:
    rankingDB();
    ~rankingDB();
    bool updateDB() const;
    bool listplayerDB(std::string m_nick) const;
    short CheckPlayerDB(player m_user) const; //returns SQL info about location of this player

};

#endif  //rankingDB_H_