#include "Menu.h"

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

    return (selected == options.end() ? 0 : (selected - options.begin() + 1));
}

size_t Menu::handleMenu(bool isHorizontal) {
    int key = getch();
    size_t selected = getSelected();
    while (true) {
        if ((key == 10 && selected != 0) || (key == 27 && selected == 0)) {
            break;
        }

        if (isHorizontal) {
            if (key == KEY_RIGHT) {
                next();
            } else if (key == KEY_LEFT) {
                prev();
            }
        } else {
            if (key == KEY_DOWN) {
                next();
            } else if (key == KEY_UP) {
                prev();
            }
        }

        if (key == 27) {
            unselect();
        }

        key = getch();
        selected = getSelected();
    }

    return selected;
}
