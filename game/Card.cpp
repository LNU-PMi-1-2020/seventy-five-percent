#include "Card.h"
#include "Game.h"

#include <utility>

using std::to_string;

Card::Card(size_t id, string firstName, string lastName, string middleName, string party,
           int level, int mana, int luck, int strength, string description, int price) :
        id(id),
        firstName(std::move(firstName)), lastName(std::move(lastName)), middleName(std::move(middleName)),
        party(std::move(party)), level(level),
        mana(mana), luck(luck), strength(strength),
        description(std::move(description)), price(price) {}

void Card::draw(Box *box) {
    box->drawBorder();
    box->verticalCenterText(1, lastName);
    box->verticalCenterText(2, firstName + " " + middleName);
    box->verticalCenterText(3, "[" + party + "] " + to_string(level) + " рівень");

    box->text("Сила: " + to_string(strength), 2, 5);
    box->text("Мана: " + to_string(mana), 2, 6);
    box->text("Удача: " + to_string(luck), 2, 7);

//    string descBoxName = box->getName() + "-desc";
//    if (!Game::get().boxes.contains(descBoxName)) {
//        int w = box->getWidth() - 4;
//        int h = box->getHeight() - 10;
//        auto nBox = new Box(descBoxName, box, 2, 9, w, h);
//        box->text(nBox->desc(), 2, 9);
//        Game::get().boxes[descBoxName] = nBox;
//    }
//
//    Game::get().boxes[descBoxName]->text(description);
//    Game::get().boxes[descBoxName]->refresh();

    box->refresh();
}

