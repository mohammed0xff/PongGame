#include "game.hpp"


int main(int argc, char* argv[]) {

    Game game;
    if (game.init()) {
        game.Run();
    }
    return 0;
}