#include "rankingDB.h"

 /*           
rankingDB::rankingDB() {

    m_SQLserver = "tcp://localhost:3306";
    m_SQLuser = "root";
    m_SQLpass = "";

    this->connectDB();
}*/

//DB class methods
DB::DB(std::string SQLserver, std::string SQLuser, std::string SQLpass, std::string SQLschema) {

    m_SQLserver = SQLserver;
    m_SQLuser = SQLuser;
    m_SQLpass = SQLpass;
    m_driver = get_driver_instance();
    m_con = m_driver->connect(m_SQLserver, m_SQLuser, m_SQLpass);
    m_con->setSchema(SQLschema);

}


DB::~DB() {
    delete m_con;
}



//rankingDB class methods
rankingDB::rankingDB(std::string SQLserver, std::string SQLuser, std::string SQLpass, std::string SQLschema, std::string SQLtable) 
: DB(SQLserver, SQLuser, SQLpass, SQLschema) {

    m_SQLtable = SQLtable;

}

rankingDB::~rankingDB() {

}

bool rankingDB::updateDB(const std::string nick, const long points) const {

    sql::PreparedStatement *pstm;

    pstm = m_con->prepareStatement("UPDATE ? SET points = ? WHERE nick LIKE ?");
    pstm->setString(1, m_SQLtable);
    pstm->setInt(2, points);
    pstm->setString(3, nick);
    pstm->execute();

    delete pstm;

    return true;
}

bool rankingDB::listplayersDB(const std::string m_nick) const {

    sql::PreparedStatement *pstm;
    sql::ResultSet *res;

    pstm = m_con->prepareStatement("SELECT * FROM ? ORDER BY points DESC");
    pstm->setString(1, m_SQLtable);
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

    pstm = m_con->prepareStatement("SELECT id, nick, points FROM ? WHERE nick LIKE ?");
    pstm->setString(1, m_SQLtable);
    pstm->setString(2, m_nick);
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

bool rankingDB::addplayerDB(std::string m_nick) const {

    sql::PreparedStatement *pstm;

    pstm = m_con->prepareStatement("INSERT INTO ? (nick, points) VALUES(?,?)");
    pstm->setString(1, m_SQLtable);
    pstm->setString(2, m_nick);
    pstm->setInt(3, 0);
    pstm->execute();

    delete pstm;

    return true;
}

/*bool rankingDB::remplayerDB() const {
    return true;
}*/



//clueDB class methods
clueDB::clueDB(const std::string & SQLserver, const std::string & SQLuser, const std::string & SQLpass, const std::string & SQLschema, const std::string & SQLtable) 
: DB (SQLserver, SQLuser, SQLpass, SQLschema) {

    m_SQLtable = SQLtable;
}

clueDB::~clueDB() {

}

std::string clueDB::randomClueDB() const {

    sql::PreparedStatement *pstm;
    sql::ResultSet *res;
    
    pstm = m_con->prepareStatement("SELECT * FROM ? ORDER BY RAND() LIMIT 1");
    pstm->setString(1, m_SQLtable);
    res = pstm->executeQuery();

    std::string random_clue = "";

    if (res->next())
        random_clue = res->getString("word");
    else
        std::cout<<"Check Hangman DB/clue table if it is not empty\n";
        /*
        throw exception
        */

    delete pstm;

    return random_clue;
    
}

bool clueDB::addClueDB(const std::string & candidate_clue) {

    sql::PreparedStatement *pstm;
    sql::ResultSet *res;

    pstm = m_con->prepareStatement("SELECT word FROM ? WHERE word LIKE ?");
    pstm->setString(1, m_SQLtable);
    pstm->setString(2, candidate_clue);
    res = pstm->executeQuery();

    if(res->next()) 
        std::cout<<"This clue is already known in our DB\n";
    else
    {
        pstm = m_con->prepareStatement("INSERT INTO ? (word, valid) VALUES (?,?)");
        pstm->setString(1, m_SQLtable);
        pstm->setInt(2, 0);                      //set valid to 0 if it become 3 it will be approved, if -3 then it will be rejected
        pstm->execute();
        std::cout<<"Thank you! Your clue candidate will be validated\n";
    }
    delete pstm;

    return true; //there should be implemented condition if SQL read/write succeed and then return true or false
}

bool clueDB::remClueDB(const std::string & candidate_clue) {



}