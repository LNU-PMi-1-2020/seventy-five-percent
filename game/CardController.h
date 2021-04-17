#ifndef SEVENTY_FIVE_PERCENT_CARD_CONTROLLER_H
#define SEVENTY_FIVE_PERCENT_CARD_CONTROLLER_H

#include <map>
#include "Card.h"

class CardController {
private:
    CardController() = default;

public:
    static CardController &get();

    CardController &operator=(CardController &) = delete;

    CardController(const CardController &) = delete;

    std::map<size_t , Card *> cards;

    void loadCards();
};

#endif //SEVENTY_FIVE_PERCENT_CARD_CONTROLLER_H
