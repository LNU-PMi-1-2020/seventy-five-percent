#include "Game.h"
#include <ncurses.h>
#include "../utils/Printer.h"
#include "CardController.h"
#include "menu/Menu.h"
#include "Player.h"
#include "menu/MenuOption.h"
#include "menu/TextMenuOption.h"
#include "menu/FuncMenuOption.h"

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

    auto &m = Menu::get();

    static bool initialized;
    if (!initialized) {
        initialized = true;

        boxes["playButton"] = new Box("playButton", boxes["main"], .5, .55, 15, 3);
        boxes["aboutButton"] = new Box("aboutButton", boxes["main"], .5, .65, 15, 3);
        boxes["exitButton"] = new Box("exitButton", boxes["main"], .5, .75, 15, 3);
        refresh();

        m.menus["main"] = {
                new FuncMenuOption([] {}),
                new TextMenuOption(boxes["playButton"], "Грати", [] {
                    if (Player::get().newGame) {
                        Game::get().drawNewGameScreen();
                    } else {
                        Game::get().drawContinueGameScreen();
                    }
                }),
                new TextMenuOption(boxes["aboutButton"], "Про гру", [] {}),
                new TextMenuOption(boxes["exitButton"], "Вийти", [] {})
        };
    }

    m.currentlyActive = "main";
    m.draw();

    m.handleMenu(false, false);
}

void Game::drawNewGameScreen() {
    clear();
    refresh();

    boxes["main"]->centerText("Play new game!");

    auto &m = Menu::get();

    static bool initialized;
    if (!initialized) {
        initialized = true;

        boxes["test1"] = new Box("test1", boxes["main"], 1, 1, 8, 1);
        boxes["test2"] = new Box("test2", boxes["main"], 1 + 8 + 2, 1, 8, 1);
        boxes["test3"] = new Box("test3", boxes["main"], 1 + (8 + 2) * 2, 1, 8, 1);

        m.menus["test"] = {
                new TextMenuOption(boxes["test1"], "Test 1", [] {
                    mvprintw(3, 0, "1");
                    Menu::get().handleMenu(true);
                }, false),
                new TextMenuOption(boxes["test2"], "Test 2", [] {
                    mvprintw(3, 0, "2");
                    Menu::get().handleMenu(true);
                }, false),
                new TextMenuOption(boxes["test3"], "Test 3", [] {
                    mvprintw(3, 0, "3");
                    Menu::get().handleMenu(true);
                }, false)
        };
    }

    m.currentlyActive = "test";
    m.draw();

    m.handleMenu(true);

    getch();
}

void Game::drawContinueGameScreen() {
    clear();
    refresh();

    boxes["main"]->centerText("Continue to play game!");

    getch();
}
