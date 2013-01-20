#include "Viewport.h"

Viewport::Viewport() :
    scale(1, 1)
{
}

void Viewport::setScreenSize(vec2 size) {
    scale = size / vec2(SCREEN_WIDTH, SCREEN_HEIGHT);
}

vec2 Viewport::transform(vec2 input) const {
    return input * scale;
}
