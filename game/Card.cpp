#include "Card.h"

#include <utility>

Card::Card(size_t id, string firstName, string lastName, string middleName, string party,
           int level, int mana, int luck, int strength, string description, int price) :
        id(id),
        firstName(std::move(firstName)), lastName(std::move(lastName)), middleName(std::move(middleName)),
        party(std::move(party)), level(level),
        mana(mana), luck(luck), strength(strength),
        description(std::move(description)), price(price) {}
