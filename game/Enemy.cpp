#include "Enemy.h"

Enemy &Enemy::get() {
    static Enemy enemy;
    return enemy;
}
