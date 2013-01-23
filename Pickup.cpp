#include "Pickup.h"
#include "Helicopter.h"

Pickup::Pickup(vec2 pos) :
    Body(pos, vec2(20, 20))
{
}

void Pickup::update(float delta) {
    if (position.x < 0) {
        destroy();
    }
}

void Pickup::draw() const {
    drawUI(position);
}

void Pickup::contactNotify(Body *body) {
    Helicopter *heli = dynamic_cast<Helicopter*>(body);
    if (heli) {
        onPickup(heli);
    }
}

void Pickup::remove() {
    position.x = 999999999;
}
