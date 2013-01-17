#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "Body.h"

class Helicopter : public Body {
public:
    Helicopter(float w, float h);

    virtual void update(float delta);
    virtual void draw() const;

protected:
    vec2 velocity;
};

#endif
