#include "Explosion.h"
#include "Helicopter.h"
#include "Pickups.h"
#include "Input.h"

BlinkPickup::BlinkPickup(vec2 pos) :
    Pickup(pos)
{
}

void BlinkPickup::drawUI(vec2 pos) const {
    GfxState gfx(0xFF00FF, 0);
    
    gfx.drawEllipse(pos, size, false);
}

void BlinkPickup::onPickup(Body* heli) {
    dynamic_cast<Helicopter*>(heli)->addPowerup(new BlinkPowerup(this));
    
    remove();
}

bool BlinkPowerup::evaluate() const {
    return true;
}

void BlinkPowerup::update(float delta) {
    static const size_t TELEPORT_ANIMS = 10;
    
    vec2 src = instigator->position;
    vec2 dir = (input.cursor - src) / TELEPORT_ANIMS;
    
    for (size_t i = 0; i < TELEPORT_ANIMS; i++)
        parentState->create(new Explosion(src + dir * (i + 1), 0.5f, 5 * i, 0x00AAFF));
    
    instigator->position = input.cursor;
    destroy();
}
