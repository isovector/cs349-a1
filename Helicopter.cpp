#include "Helicopter.h"
#include "Input.h"

#include "Projectile.h"

#include <iostream>
using namespace std;

Helicopter::Helicopter(float w, float h) :
    Body(vec2(0, 0), vec2(w, h), CG_FRIEND, false),
    velocity(0, 200)
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
