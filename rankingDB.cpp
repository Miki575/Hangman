#include "rankingDB.h"
            
rankingDB::rankingDB() {

    SQLserver = "tcp://localhost:3306";
    SQLuser = "root";
    SQLpass = "";
}

rankingDB::~rankingDB() {
    delete con;
}

bool rankingDB::addplayerDB() const {
    return true;
}

bool rankingDB::remplayerDB() const {
    return true;
}

bool rankingDB::connectDB() {
    driver = get_driver_instance();
    con = driver->connect(SQLserver, SQLuser, SQLpass);
    con->setSchema("Hangman");

    if ("ConnectionOK")
        return true;
    else
        return false;
    
}

bool rankingDB::updateDB() const {
    return true;
}

bool rankingDB::listplayerDB(std::string m_nick) const {
    return true;
}

short rankingDB::CheckPlayerDB(player m_user) const{
    return 0;
}