#include "ball.hpp"
#include "universals.hpp"
#include "collisionDetection.hpp"
#include <cmath>

Ball::Ball(Body body, float horizontalVelocity, float verticalVelocity) 
    : body(body)
    , horizontalVelocity(horizontalVelocity)
    , verticalVelocity(verticalVelocity)
    
{
}

Ball::~Ball() {
}

void Ball::update(Body playerOne, Body playerTwo) {

    this->body.x += this->horizontalVelocity;
    this->body.y += this->verticalVelocity;

    if (this->body.y + this->body.height > SCREEN_HEIGHT || this->body.y < 0) {
        this->verticalVelocity *= -1;
    }

    if (body.x < SCREEN_WIDTH / 2) {

        int playerOneCollision = CollisionDetection::checkLeftCollision(this->body, playerOne);
        if (playerOneCollision != 0) {
            this->verticalVelocity = playerOneCollision * fabsf(this->verticalVelocity);
            this->horizontalVelocity *= -1;
        }
    }
    else {

        int playerTwoCollision = CollisionDetection::checkRightCollision(this->body, playerTwo);
        if (playerTwoCollision != 0) {
            this->verticalVelocity = playerTwoCollision * fabsf(this->verticalVelocity);
            this->horizontalVelocity *= -1;
        }
    }

}

void Ball::restart(float horizontalVelocity, float verticalVelocity) {
    body.x = SCREEN_WIDTH / 2;
    body.y = SCREEN_HEIGHT / 2;
    this->verticalVelocity = verticalVelocity;
    this->horizontalVelocity = horizontalVelocity;
}


SDL_FPoint Ball::getPosition() {
    return SDL_FPoint{body.x, body.y};
}


Body Ball::getBody() {
    return this->body;
}


SDL_Texture* Ball::getTexuture() {
    return m_texture;
}


void Ball::loadTexuture(SDL_Texture* texture) {
    m_texture = texture;
}