#include "Menu.h"

MenuOption::MenuOption(int id, Box *box, string text, bool hasBorder) : id(id), box(box), text(std::move(text)),
                                                                        hasBorder(hasBorder) {
    if (id == 0) {
        throw std::invalid_argument("Menu option id have to be non zero");
    }
}

bool MenuOption::isSelected() const {
    return selected;
}

void MenuOption::setSelected(bool isSelected) {
    MenuOption::selected = isSelected;
}

size_t MenuOption::getId() const {
    return id;
}

void MenuOption::draw() {
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

void MenuOption::redraw() {
    if (selected) {
        box->setStandout(true);
    }
    box->centerText(text);
    if (selected) {
        box->setStandout(false);
    }

    box->refresh();
}

Menu &Menu::get() {
    static Menu menu;
    return menu;
}

void Menu::next() {
    auto options = menus[currentlyActive];
    auto selected = std::find_if(options.begin(), options.end(), [](const MenuOption *mo) { return mo->isSelected(); });

    if (selected == options.end()) {
        auto o = options[0];
        o->setSelected(true);
        o->redraw();
    } else {
        size_t i = selected - options.begin();
        options[i]->setSelected(false);
        options[i]->redraw();

        i = (i + 1) % options.size();
        options[i]->setSelected(true);
        options[i]->redraw();
    }
}

void Menu::prev() {
    auto &options = menus[currentlyActive];
    auto selected = std::find_if(options.begin(), options.end(), [](const MenuOption *mo) { return mo->isSelected(); });

    if (selected == options.end()) {
        auto o = options[0];
        o->setSelected(true);
        o->redraw();
    } else {
        size_t i = selected - options.begin();
        options[i]->setSelected(false);
        options[i]->redraw();

        i = (i - 1) % options.size();
        if (i < 0) {
            i += options.size();
        }
        options[i]->setSelected(true);
        options[i]->redraw();
    }
}

void Menu::unselect() {
    auto &options = menus[currentlyActive];
    auto selected = std::find_if(options.begin(), options.end(), [](const MenuOption *mo) { return mo->isSelected(); });

    if (selected != options.end()) {
        (*selected)->setSelected(false);
        (*selected)->redraw();
    }
}

void Menu::draw() {
    for (auto &mo : menus[currentlyActive]) {
        mo->draw();
    }
}

size_t Menu::getSelected() {
    auto &options = menus[currentlyActive];
    auto selected = std::find_if(options.begin(), options.end(), [](const MenuOption *mo) { return mo->isSelected(); });

    return (selected == options.end() ? 0 : (*selected)->getId());
}