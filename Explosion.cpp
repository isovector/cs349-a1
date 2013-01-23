#include "Explosion.h"

#include <iostream>
using namespace std;

Explosion::Explosion(vec2 pos, float dur, float siz, unsigned long col) :
    Entity(pos),
    elapsed(0.0f),
    duration(dur),
    size(siz),
    color(col)
{
}

void Explosion::update(float delta) {
    elapsed += delta;
    if (elapsed >= duration)
        destroy();
}

void Explosion::draw() const {
    GfxState gfx(color, 0);
    
    int length = static_cast<int>(elapsed / duration * size);
    vec2 size(length, length);
    
    gfx.drawEllipse(position - size / 2, size);
}
