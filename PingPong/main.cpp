#include "Player.h"
#include "Ball.h"
#include "setup.h"

int main() {

  setup game;

    // Game loop
        game.input();
        game.logic();
        game.draw();
    return 0;
}

