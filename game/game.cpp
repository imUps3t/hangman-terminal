#include "game.h"
#include "../utils.h"

#include <iostream>
#include <string>

Game::Game(std::string word, int triesBeforeDeath) : word{Utils::to_lowercase(word)}, triesBeforeDeath{triesBeforeDeath} {
    for (int i = 0; i < word.length(); i++) {
        word_copy.append("_");
    }
}

void Game::start() {
    remainingTries = triesBeforeDeath;
    system("clear");

    bool looping = true;

    while (looping) {
        looping = loop();
    }
}

bool Game::loop() {
    std::cout << "\n\n\n";
    std::cout << "You have " << remainingTries << " tries left" << std::endl;

    std::cout << "Current progress: " << word_copy << std::endl;
    
    std::cout << "\n" << "Enter letter: ";

    std::string letter;
    std::cin >> letter;
    letter = Utils::to_lowercase(letter);

    if(letter.length() != 1) {
        std::cout << "You must type exactly one letter" << std::endl;
        return true;
    }

    size_t last_instance{word.find(letter)};

    if (last_instance == std::string::npos) {
        std::cout << "Wrong letter!" << std::endl;
        remainingTries--;
    } else {
        std::cout << "\nFound letter: " << letter << std::endl;
        while(last_instance != std::string::npos) {

            word_copy = word_copy.substr(0, last_instance).append(letter).append(word_copy.substr(last_instance + 1));

            last_instance = word.find(letter, last_instance + 1);
        }
    }

    if (Utils::equals(word_copy, word)) {
        std::cout << "You won!" << std::endl;
        return false;
    }

    return true;

}