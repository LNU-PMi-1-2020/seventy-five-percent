#include "game/Game.h"

int main() {
    auto game = Game::get();
    game.init();
    game.run();
    game.stop();
}
