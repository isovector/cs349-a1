#include "Projectile.h"

#include "Explosion.h"

#include <iostream>
using namespace std;

Projectile::Projectile(Entity *owner, vec2 vel, CollisionGroup group) :
    Body(owner->position, vec2(6, 6), group, true),
    parent(owner),
    velocity(vel)
{
}

void Projectile::update(float delta) {
    position += velocity * delta;
    
    if ((position.x < 0.0f || position.x > SCREEN_WIDTH)
        || (position.y < 0.0f || position.y > SCREEN_HEIGHT)) {
        destroy();
    }
}

void Projectile::draw() const {
    GfxState gfx(0xFF00FF, 0);
    gfx.drawRect(position, size);
}

void Projectile::contactNotify(Body *body) {
    parentState->create(new Explosion(position, 2, 50));
    destroy();
}
