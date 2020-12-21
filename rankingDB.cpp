#include "rankingDB.h"
            
rankingDB::rankingDB() {

    SQLserver = "tcp://localhost:3306";
    SQLuser = "root";
    SQLpass = "";

    this->connectDB();
}

rankingDB::~rankingDB() {
    delete con;
}

bool rankingDB::addplayerDB(std::string m_nick) const {

    sql::PreparedStatement *pstm;

    pstm = con->prepareStatement("INSERT INTO users (nick, points) VALUES(?,?)");
    pstm->setString(1, m_nick);
    pstm->setInt(2, 0);
    pstm->execute();

    delete pstm;

    return true;
}

/*bool rankingDB::remplayerDB() const {
    return true;
}*/

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

short rankingDB::CheckPlayerDB(std::string m_nick) const{

    sql::PreparedStatement *pstm;
    sql::ResultSet *res;

    pstm = con->prepareStatement("SELECT id, nick, points FROM users WHERE nick LIKE ?");
    pstm->setString(1, m_nick);
    res = pstm->executeQuery();

    if(res->next()) {
        std::cout << "Hi, " << res->getString("nick") << "! Good to see you again.\n";
        std::cout << "You have " << res->getInt("points") << " points.";
    }
    else {
        std::cout << "Hej, " << m_nick << "! Nigdy nie jest za pozno, zeby zaczac.";
        this->addplayerDB(m_nick);
    }

    delete pstm;

    return 0;
}