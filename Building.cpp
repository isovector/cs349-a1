#include "Building.h"
#include "Turret.h"

Building::Building(float width, float height) :
    Body(vec2(SCREEN_WIDTH, SCREEN_HEIGHT - height), vec2(width, height), CG_NEUTRAL)
{
}

void Building::update(float delta) {
    if (position.x < -size.x)
        destroy();
}

void Building::draw() const {
    GfxState gfx(0x333333, 0);
    gfx.drawRect(position, size);
}

void Building::contactNotify(Body *body) {
    Turret *turret = dynamic_cast<Turret*>(body);
    if (!turret) {
        destroy();
    }
}
