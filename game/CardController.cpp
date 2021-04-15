#include "CardController.h"

CardController &CardController::get() {
    static CardController cardController;
    return cardController;
}

void CardController::loadCards() {
    cards[0] = new Card();
}
