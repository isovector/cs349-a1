#include "Building.h"

Building::Building(float width, float height) :
    Body(vec2(SCREEN_WIDTH, SCREEN_HEIGHT - height), vec2(width, height), CG_NEUTRAL)
{
}

void Building::update(float delta) {
    if (position.x < -size.x)
        destroy();
}

void Building::draw() const {
    XFillRectangle(display, buffer, gc, UNPACKI(position), UNPACKI(size));
}

void Building::contactNotify(Body *body) {
    destroy();
}
