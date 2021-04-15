#include "Game.h"
#include <ncurses.h>
#include "../utils/Printer.h"
#include "CardController.h"

Game &Game::get() {
    static Game game;
    return game;
}

void Game::init() {
    Printer::init();
    boxes["main"] = new Box("main");

    CardController::get().loadCards();
}

void Game::stop() {
    Printer::close();
}

void Game::run() {
    boxes["title"] = new Box("title", boxes["main"], .5, .2,
                             Printer::TITLE_LOGO_COLS + 8, Printer::TITLE_LOGO_LINES + 4);
    refresh();

    Box *titleBox = boxes["title"];

    titleBox->drawBorder();
    titleBox->setColor(Printer::COLOR_YELLOW_BLACK);
    for (int i = 0; i < Printer::TITLE_LOGO_LINES; ++i) {
        titleBox->verticalCenterText(i + 2, Printer::TITLE_LOGO[i]);
    }
    titleBox->setColor(Printer::COLOR_YELLOW_BLACK);

    titleBox->refresh();

    boxes["playButton"] = new Box("playButton", boxes["main"], .5, .45, 15, 3);
    refresh();

    boxes["playButton"]->drawBorder();
    boxes["playButton"]->centerText("Грати", true);
    boxes["playButton"]->refresh();

    boxes["exitButton"] = new Box("exitButton", boxes["main"], .5, .50, 15, 3);
    refresh();

    boxes["exitButton"]->drawBorder();
    boxes["exitButton"]->centerText("Вийти", true);
    boxes["exitButton"]->refresh();

    getch();
}
