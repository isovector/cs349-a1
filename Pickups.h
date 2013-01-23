#ifndef PICKUPS_H
#define PICKUPS_H

#include "Pickup.h"
#include "Powerup.h"

class BlinkPickup : public Pickup {
public:
    BlinkPickup(vec2 pos);
    
    virtual void drawUI(vec2 pos) const;
    virtual void onPickup(Body* heli);
};

class BlinkPowerup : public Powerup {
public:
    BlinkPowerup(Pickup *item) : Powerup(item) { }

    virtual bool evaluate() const;
    virtual void update(float delta);
};

#endif
