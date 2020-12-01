#Makefile for new Hangman- NH

#variables
CXX = g++
CXXFLAGS = -Wall -g
RM = rm -f

#target : dependencies
#	command

#create executable
all : HangmanGame

HangmanGame : main.o player.o rankingDB.o
	$(CXX) $(CXXFLAGS) -o HangmanGame player.o main.o rankingDB.o

main.o : main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

player.o : player.cpp player.h
	$(CXX) $(CXXFLAGS) -c player.cpp

rankingDB.o : rankingDB.cpp rankingDB.h
	$(CXX) $(CXXFLAGS) -c rankingDB.cpp

#clean object files
clean :
	$(RM) *.o