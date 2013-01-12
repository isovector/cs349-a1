#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "Entity.h"

class Helicopter : public Entity {
public:
    Helicopter(float w, float h);

    virtual void update(float delta);
    virtual void draw() const;

protected:
    vec2 velocity;
    vec2 size;
};

#endif
