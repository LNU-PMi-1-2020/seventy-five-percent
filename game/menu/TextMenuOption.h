#ifndef SEVENTY_FIVE_PERCENT_TEXT_MENU_OPTION_H
#define SEVENTY_FIVE_PERCENT_TEXT_MENU_OPTION_H

#include "MenuOption.h"

class TextMenuOption : public MenuOption {
private:
    Box *box;
    string text;
    bool hasBorder;
    bool selected = false;

public:
    TextMenuOption(Box *box, string text, bool hasBorder = true);

    void draw() override;

    void redraw() override;

    bool isSelected() const override;

    void setSelected(bool isSelected) override;
};

#endif //SEVENTY_FIVE_PERCENT_TEXT_MENU_OPTION_H
