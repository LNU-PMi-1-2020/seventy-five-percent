#include "Game.h"
#include <ncurses.h>
#include "../utils/Printer.h"
#include "CardController.h"
#include "menu/Menu.h"
#include "Player.h"
#include "menu/MenuOption.h"
#include "menu/TextMenuOption.h"

Game &Game::get() {
    static Game game;
    return game;
}

void Game::init() {
    Printer::init();
    boxes["main"] = new Box("main");

    CardController::get().loadCards();
    Player::get().loadPlayer();
}

void Game::stop() {
    Printer::close();
}

void Game::run() {
    drawMainScreen();
}

void Game::drawMainScreen() {
    clear();
    refresh();

    mvprintw(LINES - 1, 0, ("Version: " + VERSION).c_str());

    boxes["title"] = new Box("title", boxes["main"], .5, .3,
                             Printer::TITLE_LOGO_COLS + 8, Printer::TITLE_LOGO_LINES + 4);
    refresh();

    Box *titleBox = boxes["title"];

    titleBox->drawBorder();
    titleBox->setColor(Printer::COLOR_YELLOW_BLACK, true);
    for (int i = 0; i < Printer::TITLE_LOGO_LINES; ++i) {
        titleBox->verticalCenterText(i + 2, Printer::TITLE_LOGO[i]);
    }
    titleBox->setColor(Printer::COLOR_YELLOW_BLACK, false);

    titleBox->refresh();

    auto m = Menu::get();

    static bool initialized;
    if (!initialized) {
        initialized = true;

        boxes["playButton"] = new Box("playButton", boxes["main"], .5, .55, 15, 3);
        boxes["exitButton"] = new Box("exitButton", boxes["main"], .5, .70, 15, 3);
        refresh();

        m.menus["main"] = {
                new TextMenuOption(boxes["playButton"], "Грати"),
                new TextMenuOption(boxes["exitButton"], "Вийти")
        };
    }

    m.currentlyActive = "main";
    m.draw();

    if (m.handleMenu() == 1) {
        if (Player::get().newGame) {
            drawNewGameScreen();
        } else {
            drawContinueGameScreen();
        }
    }
}

void Game::drawNewGameScreen() {
    clear();
    refresh();

    boxes["main"]->centerText("Play new game!");

    getch();
}

void Game::drawContinueGameScreen() {
    clear();
    refresh();

    boxes["main"]->centerText("Continue to play game!");
}
