#include "Building.h"

Building::Building(float width, float height) :
    Body(vec2(600, 400 - height), vec2(width, height), CG_NEUTRAL)
{
}

void Building::update(float delta) {
    if (position.x < -size.x)
        destroy();
}

void Building::draw() const {
    XFillRectangle(display, win, gc, UNPACKI(position), UNPACKI(size));
}

void Building::contactNotify(Body *body) {
    destroy();
}
