#ifndef SEVENTY_FIVE_PERCENT_ENEMY_H
#define SEVENTY_FIVE_PERCENT_ENEMY_H

class Enemy {
private:
    Enemy() = default;

public:
    static Enemy &get();

    Enemy &operator=(Enemy &) = delete;
};

#endif //SEVENTY_FIVE_PERCENT_ENEMY_H
