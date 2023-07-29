#include <iostream>
#include <cstdlib>
enum choice{
    ROCK, 
    PAPER,
    SCISSOR
};
int getChoice();

int main () {


}
int getChoice(){
    int choice;
    do{
    std:: cout << "1.Rock\n2.Paper\n3.Scissor\nEnter a number\n";
    std:: cin >> choice;
    }while (choice <0 || choice > 2);
    return choice;
}