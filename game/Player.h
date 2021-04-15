#ifndef SEVENTY_FIVE_PERCENT_PLAYER_H
#define SEVENTY_FIVE_PERCENT_PLAYER_H

#include "../utils/Drawable.h"

class Player : public Drawable {
private:
    Player() = default;

public:
    static Player &get();

    Player &operator=(Player &) = delete;

    void draw() override;
};

#endif //SEVENTY_FIVE_PERCENT_PLAYER_H
