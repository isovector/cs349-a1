#ifndef PICKUP_H
#define PICKUP_H

#include "Body.h"

class Pickup : public Body {
public:
    Pickup(vec2 pos);

    virtual void update(float delta);
    virtual void contactNotify(Body* body);
    virtual void draw() const;

    void remove();

    virtual void drawUI(vec2 pos) const = 0;
    virtual void onPickup(Body* heli) = 0;
};

#endif
