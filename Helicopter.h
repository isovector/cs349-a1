#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "Body.h"
#include "Powerup.h"
#include <list>

class Helicopter : public Body {
public:
    Helicopter(float w, float h);

    virtual void update(float delta);
    virtual void draw() const;
    virtual void contactNotify(Body *body);

    void usePowerup();
    void addPowerup(Powerup* pu);

protected:
    std::list<Powerup*> powerups;
    vec2 velocity;
};

#endif
