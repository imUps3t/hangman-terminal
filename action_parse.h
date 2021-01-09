#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

#include "utils.h"
#include "game/game.h"

class ActionParse {

private:

    enum Action {
        ID_SelfWord,
        ID_RandomWord
    };

public:
    static bool perform_action(std::string action) {
        std::string lowercase = Utils::to_lowercase(action);

        if (Utils::equals(lowercase, "u")) {

            start_game(Action::ID_SelfWord);
            return true;
        } else if (Utils::equals(lowercase, "c")) {

            start_game(Action::ID_RandomWord);
            return true;
        } else if (Utils::equals(lowercase, "q")) {
            std::cout << "Exiting" << std::endl;
            exit(0);

            return true;
        } else {
            return false;
        }
        
    }

    static void start_game(Action action) {

        std::string word;

        if (action == Action::ID_SelfWord) {

            bool success = false;
            while(!success) {

                std::cout << "Enter word: ";
                std::cin >> word;

                if (word.find("_") != std::string::npos) {
                    std::cout << "You cannot use underscores inside of a word!\n" << std::endl;
                } else {
                     success = true;
                }
            }

            std::cout << "Using word: " << word << std::endl;

         } else if(action == ID_RandomWord) {
            bool success = false;
            while(!success) {

                srand(time(nullptr));

                std::vector<std::string> words = Utils::readFileToVector("words.txt");
                int random = rand() % words.size();

                word = words[random];

                 if (word.find("_") != std::string::npos) {
                     std::cout << "You cannot use underscores inside of a word!\n" << std::endl;
                 } else {
                     success = true;
                 }
            }
        }

        Game game = Game(word, 10);
        game.start();
    }
};