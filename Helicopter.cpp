#include "Helicopter.h"
#include "Input.h"

#include "Projectile.h"
#include "Building.h"

#include <iostream>
using namespace std;

Helicopter::Helicopter(float w, float h) :
    Body(vec2(0, 0), vec2(w, h), CG_FRIEND, false),
    velocity(0, 0)
{
}

void Helicopter::update(float delta) {
    velocity.x = (input.keyDown(XK_d) - input.keyDown(XK_a)) * 300;
    velocity.y = (input.keyDown(XK_s) - input.keyDown(XK_w)) * 300 + 150;
    
    position += velocity * delta;
    
    if (position.x <= -size.x / 2)
        loseGame();
    
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
    if (input.keyPress(XK_e))
        usePowerup();
}

void Helicopter::usePowerup() {
    if (!powerups.size())
        return;
    
    Powerup *pu = powerups.front();
    pu->setInstigator(this);
    
    if (pu->evaluate()) {
        powerups.pop_front();
        parentState->create(pu);
    }
    
    score += 100;
}

void Helicopter::draw() const {
    GfxState gfx(0x565656, 0);
    gfx.drawRect(position, size);

    gfx.change(0x00FF00, 0);
    gfx.drawRect(input.cursor, vec2(10, 10));
    
    size_t i = 0;
    for (list<Powerup*>::const_iterator it = powerups.begin(); it != powerups.end(); ++it)
        (*it)->instigatorItem->drawUI(vec2(25 + 25 * ++i, 440));
}

void Helicopter::addPowerup(Powerup* pu) {
    powerups.push_back(pu);
    score += 100;
}

void Helicopter::contactNotify(Body *body) {
    if (dynamic_cast<Building*>(body)) {
        rect2 rect = body->getRect();
        rect2 intersect = rect.intersection(getRect());
        
        if (rect.left() == intersect.left()) {
            position.x = rect.left() - size.x;
        } else if (rect.right() == intersect.right()) {
            position.x = rect.right();
        } else if (rect.bottom() == intersect.bottom()) {
            position.y = rect.bottom();
        } else if (rect.top() == intersect.top()) {
            position.y = rect.top() - size.y;
        }
    } else if (dynamic_cast<Projectile*>(body)) {
        destroy();
    }
}
