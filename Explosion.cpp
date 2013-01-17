#include "Explosion.h"

#include <iostream>
using namespace std;

Explosion::Explosion(vec2 pos, float dur, float siz) :
    Entity(pos),
    elapsed(0.0f),
    duration(dur),
    size(siz)
{
}

void Explosion::update(float delta) {
    elapsed += delta;
    if (elapsed >= duration)
        destroy();
}

void Explosion::draw() const {
    int length = static_cast<int>(elapsed / duration * size);
    
    XDrawArc(display, buffer, gc, position.x - length / 2, position.y - length / 2, length, length, 0, 9999999);
}
