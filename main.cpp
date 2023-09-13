#include <iostream>
#include <cstdlib>
#include <random>
#include "Player.h"
enum choice{
    ROCK = 1, 
    PAPER = 2,
    SCISSOR = 3
};
int getChoice();
int determineWinner(choice Player1,choice Player2);
int* Player::score = nullptr;
int main () {
    int playerCount;
    do{
    std::cout << "How many player?\n";
    std::cout << "One or two\n";
    std::cin >> playerCount;
    }while(playerCount != 1 && playerCount != 2);
    std::string name1;
    std::string name2;
    Player* Player1;
    Player* Player2;
    if (playerCount == 1){
        std::cout << "What is your Name\n";
        std::cin >> name1;
        Player1 = new Player(name1,1);
        //delete Player2;
    }else{
        std::cout << "What is the name of Player 1?\n";
        std::cin >> name1;
        Player1 = new Player(name1,1);
        std::cout << "What is the name of Player 2\n";
        std::cin >> name2;
        Player2 = new Player(name2,2);
    }
        bool wantsToPlay = true;
        do {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> distribution(1,3);
            choice cpuChoice = static_cast<choice>(distribution(gen));
            int winCounter;
            choice UserChoice = static_cast<choice>(getChoice());
            int outcome = determineWinner(UserChoice,cpuChoice);
            if (outcome == 0){
                std::cout << "Player two won\n";
                Player2->incrementCounter();
            }else if(outcome == 1){
                std::cout << "Player one won\n";
                Player1->incrementCounter();
            }else {
                std::cout << "There was a tie\n";
            }
            std::cout << "Do you want to play again?\n" << "Yes or No\n";
            std::string answer;
            std::cin >> answer;
            if (answer == "yes" || answer == "Yes"){
            
            }else {
                wantsToPlay = false;
            }
        }while(wantsToPlay);
        //Player1->incrementCounter();
        std::cout << "The Final score is " << Player1->getScore()[0] << "-" << Player2->getScore()[1]; 
        //std::cout << Player1->getName();

    
    ///////////////////////////////////
    // CPU choice 
    //////////////////////////////////
    return 0;

}

int getChoice(){
    int choice;
    do{
    std:: cout << "1.Rock\n2.Paper\n3.Scissor\nEnter a number\n";
    std:: cin >> choice;
    }while (choice <0 || choice > 3);
    return choice;
}

int determineWinner(choice Player1,choice Player2){
    switch (Player1)
    {
    case 1:
        if (Player2 == 1){
            return 2;
        }else if(Player2 == 2){
            return 0;
        }else {
            return 1;
        }
        break;
    case 2:
        if (Player2 == 1){
            return 1;
        }else if(Player2 == 2){
            return 2;           
        }else {
            return 0;       
        }
        break;
    case 3:
        if (Player2 == 1){
            return 0;
        }else if(Player2 == 2){
            return 1;
        }else {
            return 2;
        }
        break;
    default:
        return -1;
        break;
    }
}