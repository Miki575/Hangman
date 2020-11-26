#Makefile for new Hangman- NH

#variables
CXX = g++
CXXFLAGS = -Wall -g
RM = rm -f

#target : dependencies
#	command

#create executable
all : HangmanGame

HangmanGame : player.o main.o
	$(CXX) $(CXXFLAGS) -o HangmanGame player.o main.o

main.o : main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

player.o : player.cpp player.h
	$(CXX) $(CXXFLAGS) -c player.cpp

#clean object files
clean :
	$(RM) *.o