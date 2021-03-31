#Makefile for new Hangman- NH

#variables
CXX = g++
CXXFLAGS = -Wall -g -std=c++11
RM = rm -f

#target : dependencies
#	command

#create executable
all : HangmanGame

HangmanGame : main.o rankingDB.o clue.o player.o
	$(CXX) $(CXXFLAGS) -o HangmanGame player.o main.o rankingDB.o clue.o -lmysqlcppconn

main.o : main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -I/usr/include/mysql-cppconn-8/jdbc/

player.o : player.cpp clue.o rankingDB.o
	$(CXX) $(CXXFLAGS) -c player.cpp -I/usr/include/mysql-cppconn-8/jdbc/

rankingDB.o : rankingDB.cpp rankingDB.h
	$(CXX) $(CXXFLAGS) -c rankingDB.cpp -I/usr/include/mysql-cppconn-8/jdbc/

clue.o : clue.cpp clue.h 
	$(CXX) $(CXXFLAGS) -c clue.cpp 

#clean object files
clean :
	$(RM) *.o