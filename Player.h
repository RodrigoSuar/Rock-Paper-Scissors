#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
class Player{
    private:
    std::string PlayerName;
    int winCounter;
    int playerNumber;
    static int* score;
    public:
    Player();
    Player(std::string Name,int number);
    ~Player();

    //Accesor
    std::string getName(){return PlayerName;}
    int getWins(){return winCounter;}
    int* getScore(){return score;}
    //modifier
    void setName(std::string Name){PlayerName = Name;}
    void incrementCounter();



};


#endif
