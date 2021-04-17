#include "Menu.h"

Menu &Menu::get() {
    static Menu menu;
    return menu;
}

void Menu::next(bool ignoreESC) {
    auto options = menus[currentlyActive];
    auto selected = std::find_if(options.begin(), options.end(), [](const MenuOption *mo) { return mo->isSelected(); });

    if (selected == options.end()) {
        auto o = options[ignoreESC ? 0 : 1];
        o->setSelected(true);
        o->redraw();
    } else {
        size_t i = selected - options.begin();
        options[i]->setSelected(false);
        options[i]->redraw();

        i = (i + 1) % options.size();
        if (!ignoreESC && i == 0) {
            i++;
        }

        options[i]->setSelected(true);
        options[i]->redraw();
    }
}

void Menu::prev(bool ignoreESC) {
    auto &options = menus[currentlyActive];
    auto selected = std::find_if(options.begin(), options.end(), [](const MenuOption *mo) { return mo->isSelected(); });

    if (selected == options.end()) {
        auto o = options[options.size() - 1];
        o->setSelected(true);
        o->redraw();
    } else {
        size_t i = selected - options.begin();
        options[i]->setSelected(false);
        options[i]->redraw();

        if (i == 0 || !ignoreESC && i == 1) {
            i = options.size() - 1;
        } else {
            i--;
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

    return (selected == options.end() ? 0 : (selected - options.begin() + 1));
}

void Menu::handleMenu(bool isHorizontal, bool ignoreESC) {
    int key = getch();
    size_t selected = getSelected();
    while (true) {
        if (key == 10 && selected != 0) {
            menus[currentlyActive][selected - 1]->onPress();
            break;
        } else if (!ignoreESC && key == 27 && selected == 0) {
            menus[currentlyActive][0]->onPress();
            break;
        }

        if (isHorizontal) {
            if (key == KEY_RIGHT) {
                next(ignoreESC);
            } else if (key == KEY_LEFT) {
                prev(ignoreESC);
            }
        } else {
            if (key == KEY_DOWN) {
                next(ignoreESC);
            } else if (key == KEY_UP) {
                prev(ignoreESC);
            }
        }

        if (key == 27) {
            unselect();
        }

        key = getch();
        selected = getSelected();
    }
}
