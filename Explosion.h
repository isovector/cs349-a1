#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Entity.h"

class Explosion : public Entity {
public:
    Explosion(vec2 pos, float duration, float size);
    
    virtual void update(float delta);
    virtual void draw() const;
    
    float elapsed;
    float duration;
    float size;
};

#endif
