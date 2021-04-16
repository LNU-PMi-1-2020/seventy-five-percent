#include "Player.h"

Player &Player::get() {
    static Player player;
    return player;
}

void Player::loadPlayer() {
//    TODO if not new game set newGame = false
}
