#include "rankingDB.h"
            
rankingDB::rankingDB() {

    m_SQLserver = "tcp://localhost:3306";
    m_SQLuser = "root";
    m_SQLpass = "";

    this->connectDB();
}

rankingDB::rankingDB(std::string SQLserver, std::string SQLuser, std::string SQLpass) {

    m_SQLserver = SQLserver;
    m_SQLuser = SQLuser;
    m_SQLpass = SQLpass;

    this->connectDB();
}


rankingDB::~rankingDB() {
    delete m_con;
}

bool rankingDB::addplayerDB(std::string m_nick) const {

    sql::PreparedStatement *pstm;

    pstm = m_con->prepareStatement("INSERT INTO users (nick, points) VALUES(?,?)");
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
    m_driver = get_driver_instance();
    m_con = m_driver->connect(m_SQLserver, m_SQLuser, m_SQLpass);
    m_con->setSchema("Hangman");

    if ("ConnectionOK")
        return true;
    else
        return false;
    
}

bool rankingDB::updateDB(const std::string m_nick, const long m_points) const {

    sql::PreparedStatement *pstm;

    pstm = m_con->prepareStatement("UPDATE users SET points = ? WHERE nick LIKE ?");
    pstm->setInt(1, m_points);
    pstm->setString(2, m_nick);
    pstm->execute();

    delete pstm;

    return true;
}

bool rankingDB::listplayersDB(const std::string m_nick) const {

    sql::PreparedStatement *pstm;
    sql::ResultSet *res;

    pstm = m_con->prepareStatement("SELECT * FROM users ORDER BY points DESC");
    res = pstm->executeQuery();


    std::cout<<std::setw(13)<<"NICK"<<std::setw(13)<<"SCORE\n";
    while(res->next()) {
        std::cout<<std::setw(13)<<res->getString("nick")<<std::setw(13)<<res->getInt("points")<<std::endl;
    }

    delete pstm;

    return true;
}

short rankingDB::CheckPlayerDB(const std::string m_nick) const{

    sql::PreparedStatement *pstm;
    sql::ResultSet *res;

    pstm = m_con->prepareStatement("SELECT id, nick, points FROM users WHERE nick LIKE ?");
    pstm->setString(1, m_nick);
    res = pstm->executeQuery();

    if(res->next()) {
        std::cout << "Hi, " << res->getString("nick") << "! Good to see you again.\n";
        std::cout << "You have " << res->getInt("points") << " points.\n";
    }
    else {
        std::cout << "Hi, " << m_nick << "! It's never too late to start!\n";
        this->addplayerDB(m_nick);
    }

    delete pstm;

    return 0;
}