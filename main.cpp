#include <iostream>
#include "action_parse.h"

void printIntroText();
bool askForCommand();

int main() {

    printIntroText();
    
    while(true) {

        bool ask = askForCommand();
        if(!ask) {
            std::cout << "\nInvalid command\n";
        }
    }

    return 0;
}

bool askForCommand() {
    std::cout << "What would you like to do?" << std::endl;

    std::cout << "(U) Begin hangman with your own word" << std::endl;
    std::cout << "(C) Begin hangman with computer-generated word" << std::endl;
    std::cout << "(Q) Quit" << std::endl;

    std::cout << "command > ";

    std::string command;
    std::cin >> command;

    return ActionParse::perform_action(command);;
}

void printIntroText() {
    std::cout << "*** hangman by ups3t ***" << std::endl;
}