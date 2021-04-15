#ifndef SEVENTY_FIVE_PERCENT_GAME_H
#define SEVENTY_FIVE_PERCENT_GAME_H

#include <iostream>
#include <map>
#include "../utils/Box.h"

class Game {
private:
    Game() = default;

public:
    static Game &get();

    Game &operator=(Game &) = delete;

    std::map<const std::string, Box *> boxes;

    void init();

    void stop();

    void run();

};

#endif //SEVENTY_FIVE_PERCENT_GAME_H

