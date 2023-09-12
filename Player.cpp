#include "Player.h"


Player:: Player(){
    PlayerName = "";
    winCounter = 0;
}

Player::Player(std::string Name,int number){
    setName(Name);
    playerNumber = number;
    winCounter = 0;
    score = new int[2];
    score[0] = 0;
    score[1] = 0;
}

Player::~Player(){

}

void Player::incrementCounter(){
    winCounter++;
    if (playerNumber == 1){
        score[0]++;
    }else {
        score[1]++;
    }
}


