#include "Player.h"

void Player::draw() {

}

Player &Player::get() {
    static Player player;
    return player;
}
