#pragma once 

#include "SDL.h"
#include <memory>
#include <iostream>
#include "body.hpp"

class Ball {

public:
    Ball(Body body, float horizontalVelocity, float verticalVelocity);
    ~Ball();

    void update(Body playerBody, Body enemyBody);
    void restart( float horizontalVelocity, float verticalVelocity);

    Body getBody();
    SDL_FPoint getPosition();

    SDL_Texture* getTexuture();
    void loadTexuture(SDL_Texture* texture);

private:
    Body body;
    float verticalVelocity;
    float horizontalVelocity;
    SDL_Texture* m_texture;
};


 