#include "Powerup.h"

Powerup::Powerup(Pickup *item) :
    instigatorItem(item)
{
}

void Powerup::setInstigator(Entity *owner) {
    instigator = owner;
}

void Powerup::destroy() {
    instigatorItem->destroy();
    Object::destroy();
}
