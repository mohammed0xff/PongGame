#pragma once
#include "SDL.h"

class Body {

public:
    Body(float x, float y, float width, float height);
    ~Body();

    float x;
    float y;
    float width;
    float height;
};
