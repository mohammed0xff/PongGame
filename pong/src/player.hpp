#pragma once 
 
#include "SDL.h"
#include <iostream>
#include "body.hpp"

class Player {
public:
    Player(Body body);
    ~Player();

    void update();
    void handleInput(SDL_Event *event);

    Body getBody();
    SDL_FPoint getPosition();

    void setTexture(SDL_Texture* _texture);
    SDL_Texture* getTexuture();

    void moveUp();
    void moveDown();

    void stopUp();
    void stopDown();

    void scoreUp();
    int getScore() ;

private:
    Body body;
    int score;
    float velocity;
    bool movingUp;
    bool movingDown;
    SDL_Texture* m_texture;
};
 