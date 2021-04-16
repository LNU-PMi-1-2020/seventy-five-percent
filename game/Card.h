#ifndef SEVENTY_FIVE_PERCENT_CARD_H
#define SEVENTY_FIVE_PERCENT_CARD_H

#include <iostream>

using std::string;

class Card {
private:
    size_t id;

    string firstName;

    string lastName;

    string middleName;

    string party;

    int level;

    int mana;

    int luck;

    int strength;

    string description;

    int price;

public:
    Card() = default;

    Card(size_t id, string firstName, string lastName, string middleName, string party,
         int level, int mana, int luck, int strength, string description, int price);

};

#endif //SEVENTY_FIVE_PERCENT_CARD_H
