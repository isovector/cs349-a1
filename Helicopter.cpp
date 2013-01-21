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
    velocity.x = (input.keyDown(XK_Right) - input.keyDown(XK_Left)) * 300;
    velocity.y = (input.keyDown(XK_Down) - input.keyDown(XK_Up)) * 300 + 150;
    
    position += velocity * delta;
    
    if (position.x < 0)
        position.x = 0;
    if (position.x > SCREEN_WIDTH - size.x)
        position.x = SCREEN_WIDTH - size.x;
    
    if (position.y < 0)
        position.y = 0;
    if (position.y > SCREEN_HEIGHT - size.y)
        position.y = SCREEN_HEIGHT - size.y;
    
    if (input.keyPress(XK_space))
        parentState->create(new Projectile(this, vec2(200, 400) + velocity, CG_FRIEND));
}

void Helicopter::draw() const {
    GfxState gfx(0x565656, 0);
    gfx.drawRect(position, size);

    gfx.change(0x00FF00, 0);
    gfx.drawRect(input.cursor, vec2(10, 10));
}
