#pragma once 

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "displayManager.hpp"


class Game {
public:
    Game();
    ~Game();

    bool init();
    void Run();
    void handleInput();
    bool isRunning();

private:

    std::unique_ptr<Ball> ball;
    std::unique_ptr<Player> playerOne;
    std::unique_ptr<Player> playerTwo;

    DisplayManager displayManager;
    std::unique_ptr <SDL_Event> event;
    
    bool running;
};
 