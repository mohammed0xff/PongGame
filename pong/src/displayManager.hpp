#pragma once 


#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include <string>
#include "ball.hpp"
#include "player.hpp"

class DisplayManager {

public:
    DisplayManager();
    ~DisplayManager();

    bool init();
    bool loadMedia();
    SDL_Texture* loadTexture(std::string path);
    void Render(std::unique_ptr <Player> &p1, std::unique_ptr <Player> &p2, std::unique_ptr <Ball> &b);

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    TTF_Font * m_font;
};
