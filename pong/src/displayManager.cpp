#include "displayManager.hpp"
#include "universals.hpp"
#include <iostream>
#include <string>

DisplayManager::DisplayManager() {
    
}

DisplayManager::~DisplayManager() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
}

bool DisplayManager::init() {
    // Initializing SDL     
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not be initialized.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::cerr << "SDL_image could not be initialized.\n";
        std::cerr << "SDL_image Error : % s\n", IMG_GetError(), "\n";;
        return false;
    }

    if (TTF_Init() == -1) {
        std::cerr << "SDL_ttf could not be initializeed.\n";
        std::cerr << "SDL_ttf Error : % s\n", TTF_GetError(), "\n";;
        return false;
    }
    
    // Create Window
    m_window = SDL_CreateWindow("Pong",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);

    if (m_window == nullptr) {
        std::cout << "Error creating window..\n";
        std::cerr << SDL_GetError() << "\n";
        return false;
    }

    // Create renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (m_renderer == nullptr) {
        std::cerr << "Error creating renderer..\n";
        std::cerr << SDL_GetError() << "\n";
        return false;
    }

    if (loadMedia() == 0) {
        return false;
    }

    return true;
}

bool DisplayManager::loadMedia() {
    m_font = TTF_OpenFont(SCREEN_FONT.c_str(), 28);
    if (m_font == NULL) {
        std::cerr << "Failed to load font! SDL_ttf Error: %s\n";
        std::cerr << "SDL_ttf Error : % s\n", TTF_GetError();
        return false;
    }
    return true;
}

void DisplayManager::Render(std::unique_ptr <Player>& p1, std::unique_ptr <Player>& p2, std::unique_ptr <Ball>& ball) {
    
    SDL_Rect block;
    block.h = BLOCK_HEIGHT;
    block.w = BLOCK_WIDTH;

    // Clear screen
    SDL_SetRenderDrawColor(m_renderer, 30, 30, 30, 255);
    SDL_RenderClear(m_renderer);

    //  color 
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 0, 255);

    // player one 
    block.x = p1->getPosition().x;
    block.y = p1->getPosition().y;
    SDL_RenderCopy(m_renderer, p1->getTexuture(), NULL, &block);

    // player two
    block.x = p2->getPosition().x;
    block.y = p2->getPosition().y;
    SDL_RenderCopy(m_renderer, p2->getTexuture(), NULL, &block);

    // ball 
    block.w = BALL_WIDTH;
    block.h = BALL_HEIGHT;
    block.x = ball->getPosition().x;
    block.y = ball->getPosition().y;
    SDL_RenderCopy(m_renderer, ball->getTexuture(), NULL, &block);

    SDL_RenderDrawLine(m_renderer, MIDDLE_POINT, 0, MIDDLE_POINT, MIDDLE_POINT);

    // score 
    std::string score =  std::to_string(p1->getScore()) + " : " + std::to_string(p2->getScore());
    SDL_Surface * scoreSurface = TTF_RenderText_Solid(m_font, score.c_str(), { 0xFF, 0xFF, 0xFF, 0xFF });
    SDL_Texture * scoreTexture = SDL_CreateTextureFromSurface(m_renderer, scoreSurface);
    SDL_Rect scoreRect = { SCREEN_WIDTH / 2 - 25, 20, 50, 50 };
    SDL_RenderCopyEx(m_renderer, scoreTexture, nullptr, &scoreRect, 0.0, nullptr, SDL_FLIP_NONE);

    // display 
    SDL_RenderPresent(m_renderer);
}





SDL_Texture* DisplayManager::loadTexture(std::string path) {

    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        // (std::unique_ptr<SDL_Texture>)
        newTexture =  SDL_CreateTextureFromSurface(m_renderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}