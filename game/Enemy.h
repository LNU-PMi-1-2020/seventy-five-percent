#ifndef SEVENTY_FIVE_PERCENT_ENEMY_H
#define SEVENTY_FIVE_PERCENT_ENEMY_H

#include "../utils/Drawable.h"

class Enemy : public Drawable {
private:
    Enemy() = default;

public:
    static Enemy &get();

    Enemy &operator=(Enemy &) = delete;

    void draw() override;
};

#endif //SEVENTY_FIVE_PERCENT_ENEMY_H
