#include <iosfwd>
#include <sstream>
#include <iomanip>
#include <iostream>
#include<memory>
#include "game.hpp"
#include "universals.hpp"
#include "string.h"

Game::Game() 
    : event(nullptr)
    , running(true)
{}

Game::~Game() {
    
}

bool Game::init() {


    if (!displayManager.init()) return 0;

    Body playerOneBody(10, 10, BLOCK_WIDTH, BLOCK_HEIGHT);
    playerOne = std::make_unique<Player>(playerOneBody);
    playerOne->setTexture(displayManager.loadTexture(PLAYER_BODY));

    Body playerTwoBody(SCREEN_WIDTH - 10, 10, BLOCK_WIDTH, BLOCK_HEIGHT);
    playerTwo = std::make_unique <Player> (playerTwoBody);
    playerTwo->setTexture(displayManager.loadTexture(PLAYER_BODY));

    Body ballBody(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, BALL_WIDTH, BALL_HEIGHT);
    ball = std::make_unique <Ball> (ballBody, -BALL_VELOCITY, -BALL_VELOCITY);
    ball->loadTexuture(displayManager.loadTexture(Ball_BODY));

    event = std::make_unique<SDL_Event>();

    return true;
}



void Game::Run() {

    Uint32 timestamp = SDL_GetTicks();
    Uint32 elapsedTime = 0;
    Uint32 frameStart;
    Uint32 frameEnd;

    int frame_count = 0;

    while (isRunning()) {

        frameStart = SDL_GetTicks();
        // Do work

        handleInput();

        displayManager.Render(playerOne, playerTwo, ball);

        playerOne->update();
        playerTwo->update();
        ball->update(playerOne->getBody(), playerTwo->getBody());

        if (this->ball->getBody().x < 0) {
            playerOne->scoreUp();
            ball->restart( -BALL_VELOCITY, -BALL_VELOCITY);
        }
        else if (ball->getBody().x + ball->getBody().width > SCREEN_WIDTH) {
            playerTwo->scoreUp();;
            ball->restart( BALL_VELOCITY, -BALL_VELOCITY);
        }

        frameEnd = SDL_GetTicks();

        // Calculate duration 
        elapsedTime = frameEnd - frameStart;
        frame_count++;

        // Update the window title when completing one second
        if (frameEnd - timestamp >= 1000) {
            // renderer.UpdateStats(snake->GetScore(), frame_count);
            frame_count = 0;
            timestamp = frameEnd;
        }

        // if the work's been done quicker thatn the target fps
        // apply some delay to correct the frame rate.
        if (elapsedTime < MsPerFrame) {
            SDL_Delay(MsPerFrame - elapsedTime);
        }
    }
}



void Game::handleInput() {

    if (SDL_PollEvent(event.get()) != 0) {
        if (event->type == SDL_QUIT) {
            running = false;
        }
    }

    if (event->type == SDL_KEYDOWN) {

        switch (event->key.keysym.sym) {

        case SDLK_w:
            playerOne->moveUp();
            break;
        case SDLK_s:
            playerOne->moveDown();
            break;
        case SDLK_UP:
            playerTwo->moveUp();
            break;
        case SDLK_DOWN:
            playerTwo->moveDown();
            break;

        }
    }

    if (event->type == SDL_KEYUP) {

        switch (event->key.keysym.sym) {
        case SDLK_w:
            playerOne->stopUp();
            break;
        case SDLK_s:
            playerOne->stopDown();
            break;

        case SDLK_UP:
            playerTwo->stopUp();
            break;
        case SDLK_DOWN:
            playerTwo->stopDown();
            break;
        }
    }
}



bool Game::isRunning() {
    return running;
}

