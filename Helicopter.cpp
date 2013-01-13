#include "Helicopter.h"
#include "Input.h"

#include "Projectile.h"

#include <iostream>
using namespace std;

Helicopter::Helicopter(float w, float h) :
    Entity(vec2(0, 0), false),
    velocity(0, 200),
    size(w, h)
{
}

void Helicopter::update(float delta) {
    if (input.keyDown(XK_Down))
    {
        position.y += 200 * delta;
    }
    else if (input.keyDown(XK_Up)) {
        position.y -= 200 * delta;
    }

    if (input.keyDown(XK_Right))
    {
        position.x += 200 * delta;
    }
    else if (input.keyDown(XK_Left)) {
        position.x -= 200 * delta;
    }
    
    if (input.keyPress(XK_space)) {
        parentState->create(new Projectile(this, vec2(0, 400)));
    }
}

void Helicopter::draw() const {
    XFillRectangle(display, win, gc, UNPACKI(position), UNPACKI(size));
}
