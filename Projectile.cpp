#include "Projectile.h"

#include "Explosion.h"

Projectile::Projectile(Entity *owner, vec2 vel) :
    Body(owner->position, vec2(4, 10), CG_FRIEND, false),
    parent(owner),
    velocity(vel)
{
}

void Projectile::update(float delta) {
    position += velocity * delta;
    
    if ((position.x < 0.0f || position.x > 600.0f)
        || (position.y < 0.0f || position.y > 400.0f)) {
        destroy();
    }
}

void Projectile::draw() const {
    XFillRectangle(display, win, gc, UNPACKI(position), UNPACKI(size));
}

void Projectile::contactNotify(Body *body) {
    parentState->create(new Explosion(position, 2, 50));
    destroy();
}
