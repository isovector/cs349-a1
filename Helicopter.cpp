#include "Helicopter.h"
#include "Input.h"

#include "Projectile.h"

#include <iostream>
using namespace std;

Helicopter::Helicopter(float w, float h) :
    Body(vec2(0, 0), vec2(w, h), CG_FRIEND, false),
    velocity(0, 0)
{
}

void Helicopter::update(float delta) {
    velocity.x = (input.keyDown(XK_Right) - input.keyDown(XK_Left)) * 200;
    velocity.y = (input.keyDown(XK_Down) - input.keyDown(XK_Up)) * 200;
    
    position += velocity * delta;
    
    if (input.keyPress(XK_space)) {
        parentState->create(new Projectile(this, vec2(0, 400) + velocity));
    }
}

void Helicopter::draw() const {
    XFillRectangle(display, buffer, gc, UNPACKI(position), UNPACKI(size));
}
