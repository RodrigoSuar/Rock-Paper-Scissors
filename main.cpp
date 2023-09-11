#include <iostream>
#include <cstdlib>
#include <random>
enum choice{
    ROCK, 
    PAPER,
    SCISSOR
};
int getChoice();
int determineWinner(choice Player1,choice Player2);

int main () {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1,3);
    choice cpuChoice = static_cast<choice>(distribution(gen));
    int winCounter;
    choice UserChoice = static_cast<choice>(getChoice());
    int outcome = determineWinner(UserChoice,cpuChoice);
    if (outcome == 0){
        std::cout << "You Lost";
    }else if(outcome == 1){
        std::cout << "You Won!";
    }else {
        std::cout << "You tied";
    }

    return 0;

}

int getChoice(){
    int choice;
    do{
    std:: cout << "1.Rock\n2.Paper\n3.Scissor\nEnter a number\n";
    std:: cin >> choice;
    }while (choice <0 || choice > 2);
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
        break;
    }
}