#ifndef SEVENTY_FIVE_PERCENT_TEXT_MENU_OPTION_H
#define SEVENTY_FIVE_PERCENT_TEXT_MENU_OPTION_H

#include "MenuOption.h"

class TextMenuOption : public MenuOption {
private:
    Box *box;
    string text;
    bool hasBorder;


public:
    TextMenuOption(Box *box, string text, void (*onPress)(), bool hasBorder = true);

    void draw() override;

    void redraw() override;
};

#endif //SEVENTY_FIVE_PERCENT_TEXT_MENU_OPTION_H
