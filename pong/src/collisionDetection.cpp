#include "collisionDetection.hpp"




int CollisionDetection::checkLeftCollision(Body ball, Body paddle) {

    float ballRightX = ball.x + ball.width;
    float ballBottomY = ball.y + ball.height;
    SDL_FPoint ballCenter{
        ball.x + ball.width / 2.0,
        ball.y + ball.height / 2.0
    };

    float paddleRightX = paddle.x + paddle.width;
    float paddleBottomY = paddle.y + paddle.height;
    SDL_FPoint paddleCenter{
        paddle.x + paddle.width / 2.0,
        paddle.y + paddle.height / 2.0
    };


    if (ballCenter.y >= paddle.y && ballCenter.y <= paddleBottomY) {
        if (ball.x < paddle.x + paddle.width) {
            if (ballCenter.y > paddleCenter.y) {
                return 1;
            }
            else {
                return -1;
            }
        }
    }

    return 0;
}


int CollisionDetection::checkRightCollision(Body ball, Body paddle) {

    float ballRightX = ball.x + ball.width;
    float ballBottomY = ball.y + ball.height;
    SDL_FPoint ballCenter{ 
        ball.x + ball.width / 2.0,
        ball.y + ball.height / 2.0 
    };

    float paddleRightX = paddle.x + paddle.width ;
    float paddleBottomY = paddle.y + paddle.height ;
    SDL_FPoint paddleCenter{ 
        paddle.x + paddle.width / 2.0,
        paddle.y + paddle.height / 2.0
    };


    if (ballCenter.y >= paddle.y && ballCenter.y <= paddleBottomY) {
        if (ball.x >= paddle.x - paddle.width) {
            if (ballCenter.y > paddleCenter.y) {
                return 1;
            }
            else {
                return -1;
            }
        }
    }

    return 0;
}

