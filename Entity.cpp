#include "Entity.h"

Entity::Entity(vec2 pos, bool scrolls) :
    position(pos),
    autoScrolls(scrolls)
{
}

void Entity::draw() const {
}
