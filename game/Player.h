#ifndef SEVENTY_FIVE_PERCENT_PLAYER_H
#define SEVENTY_FIVE_PERCENT_PLAYER_H

#include <set>

class Player {
private:
    Player() = default;

public:
    bool newGame = true;

    std::set<size_t> ownedCards;

    static Player &get();

    Player &operator=(Player &) = delete;

    Player(const Player &) = delete;

    void loadPlayer();
};

#endif //SEVENTY_FIVE_PERCENT_PLAYER_H
