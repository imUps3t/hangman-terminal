#include <string>
#include <string.h>

class Game {
private:
    std::string word;
    int triesBeforeDeath;

    int remainingTries;
    std::string word_copy;

    bool loop();
public:
    Game(std::string word, int triesBeforeDeath);

    void start();
};