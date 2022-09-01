#include "player.hpp"
#include "universals.hpp"

Player::Player(Body body) 
    : velocity (PLAYER_VELOCITY)
    , body (body)
    , score(0)
    , movingDown(0)
    , movingUp(0)
{
}


Player::~Player() {
}


void Player::update() {

    if (body.y < 0) {
        stopUp();
    }
    else if (body.y + body.height > SCREEN_HEIGHT) {
        stopDown();
    }

    if (this->movingUp) {
        this->body.y += -velocity;
    }

    else if (this->movingDown) {
        this->body.y += velocity;
    }
}


void Player::handleInput(SDL_Event *event) {
    if (event->type == SDL_KEYDOWN) {
        switch (event->key.keysym.sym) {
            case SDLK_UP:
                moveUp();
                break;
            case SDLK_DOWN:
                moveDown();
                break;
        }
    }
    if (event->type == SDL_KEYUP) {
        switch (event->key.keysym.sym) {
            case SDLK_UP:
                stopUp();
                break;
            case SDLK_DOWN:
                stopDown();
                break;
        }
    }
}



void Player::moveUp() {
    this->movingDown = false;
    this->movingUp = true;
}

void Player::moveDown() {
    this->movingUp = false;
    this->movingDown = true;
}

void Player::stopUp() {
    this->movingUp = false;
}

void Player::stopDown() {
    this->movingDown = false;
}



void Player::scoreUp() {
    score++;
}

int Player::getScore() {
    return score;
}



SDL_Texture* Player::getTexuture() {
    return m_texture;
}

void Player::setTexture(SDL_Texture* _texture) {
    m_texture = _texture;
}


SDL_FPoint Player::getPosition() {
    SDL_FPoint pos;
    pos.x = body.x;
    pos.y = body.y;
    return pos;
}

Body Player::getBody() {
    return this->body;
}
