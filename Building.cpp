#include "Building.h"

Building::Building(float width, float height) :
    Entity(vec2(600, 400 - height)),
    size(width, height)
{
}

void Building::update(float delta) {
    if (position.x < -size.x)
        destroy();
}

void Building::draw() const {
    XFillRectangle(display, buffer, gc, UNPACKI(position), UNPACKI(size));
}
