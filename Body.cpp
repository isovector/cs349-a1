#include "Body.h"

Body::Body(vec2 pos, vec2 siz, CollisionGroup group, bool scrolls) 
    : Entity(pos, scrolls), size(siz), collisionGroup(group)
{
}

void Body::contactNotify(Body *body) {
}

rect2 Body::getRect() const {
    return rect2(position, size);
}
