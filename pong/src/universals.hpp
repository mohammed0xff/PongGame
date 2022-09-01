#pragma once 
#include <string>

// DISPLAY VARIABLES
constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;
constexpr int MIDDLE_POINT = SCREEN_WIDTH / SCREEN_HEIGHT;
constexpr std::size_t FPS{ 60 };
// This value is calculated when a new animation is loaded
// Changing it will not alter playback speed.
constexpr std::size_t MsPerFrame{ 1000 / FPS };


// GAME VARIABLES
const int BLOCK_WIDTH = 10;
const int BLOCK_HEIGHT = 100;
const int PLAYER_VELOCITY = 10;

const int BALL_WIDTH = 20;
const int BALL_HEIGHT = 20;
const int BALL_VELOCITY = 5;


// TEXTURES
const std::string PLAYER_BODY = "assets/playersBody.png";
const std::string Ball_BODY = "assets/ball.png";
const std::string SCREEN_FONT = "assets/Muli-Med.ttf";