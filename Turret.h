#ifndef TURRET_H
#define TURRET_H

#include "Body.h"

class Turret : public Body {
public:
    Turret(vec2 pos);

    virtual void setState(State *state);
    virtual void update(float delta);
    virtual void draw() const;
    virtual void contactNotify(Body *body);

private:
    float shootTimer;
    Body *target;
};

#endif
