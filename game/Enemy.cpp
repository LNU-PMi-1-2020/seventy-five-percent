#include "Enemy.h"

void Enemy::draw() {

}

Enemy &Enemy::get() {
    static Enemy enemy;
    return enemy;
}
