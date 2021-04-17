#include "TextMenuOption.h"

TextMenuOption::TextMenuOption(Box *box, string text, void (*onPress)(), bool hasBorder) : box(box),
                                                                                           text(std::move(text)),
                                                                                           hasBorder(hasBorder) {
    f = onPress;
}

void TextMenuOption::draw() {
    if (hasBorder) {
        box->drawBorder();
    }

    if (selected) {
        box->setStandout(true);
    }
    box->centerText(text);
    if (selected) {
        box->setStandout(false);
    }

    box->refresh();
}

void TextMenuOption::redraw() {
    if (selected) {
        box->setStandout(true);
    }
    box->centerText(text);
    if (selected) {
        box->setStandout(false);
    }

    box->refresh();
}
