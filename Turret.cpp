#include "Turret.h"
#include "Helicopter.h"
#include "Projectile.h"
#include "GameState.h"

Turret::Turret(vec2 pos) :
    Body(pos, vec2(15, 25), CG_ENEMY),
    shootTimer(1.0f),
    target(NULL)
{
}

void Turret::setState(State *state) {
    GameState *gs = dynamic_cast<GameState*>(state);
    target = gs->getObjectOfType<Helicopter>();
    Body::setState(state);
}

void Turret::update(float delta) {
    if (target && target->garbage) {
        target = NULL;
    }
    
    shootTimer -= delta;
    
    if (target && shootTimer <= 0.0f) {
        vec2 angle = target->position - position;
        parentState->create(new Projectile(this, angle * 2.0f, CG_ENEMY));
        shootTimer = 0.8f;
    }
    
    if (position.x < 0) {
        destroy();
    }
}

void Turret::draw() const {
    GfxState gfx(0x770000, 0);
    gfx.drawRect(position, size);
}

void Turret::contactNotify(Body *body) {
    if (dynamic_cast<Projectile*>(body)) {
        destroy();
        score += 500;
    }
}
