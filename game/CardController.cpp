#include "CardController.h"
#include <fstream>
#include <jsoncpp/json/json.h>

CardController &CardController::get() {
    static CardController cardController;
    return cardController;
}

void CardController::loadCards() {
    std::ifstream fileInput("resources/cards.json");
    Json::Reader reader;
    Json::Value rootObj;

    reader.parse(fileInput, rootObj);

    size_t id = 1;
    for (auto partyObj : rootObj["parties"]) {
        string party = partyObj["party"].asString();
        for (auto levelsObj : partyObj["levels"]) {
            int level = levelsObj["level"].asInt();
            for (auto cardObj : levelsObj["cards"]) {
                Card c = Card(id,
                              cardObj["firstName"].asString(), cardObj["lastName"].asString(),
                              cardObj["middleName"].asString(),
                              party, level,
                              cardObj["mana"].asInt(), cardObj["luck"].asInt(), cardObj["strength"].asInt(),
                              cardObj["description"].asString(), cardObj["price"].asInt());
                cards[id] = c;
                id++;
            }
        }
    }
}

Card CardController::operator[](const size_t id) const {
    return cards.at(id);
}
