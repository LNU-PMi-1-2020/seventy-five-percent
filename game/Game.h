#ifndef SEVENTY_FIVE_PERCENT_GAME_H
#define SEVENTY_FIVE_PERCENT_GAME_H

#include <iostream>
#include <map>
#include "../utils/Box.h"

class Game {
private:
    Game() = default;

public:
    static std::map<const std::string, Box *> boxs;

    static void init();

    static void stop();

    static void run();

//    https://github.com/tony/NCURSES-Programming-HOWTO-examples/blob/master/16-panels/show-hide.c
};


#endif //SEVENTY_FIVE_PERCENT_GAME_H

