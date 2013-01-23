#ifndef POWERUP_H
#define POWERUP_H

#include "Pickup.h"
#include "Object.h"
#include "Entity.h"

class Powerup : public Object {
public:    
    Powerup(Pickup *item);
    virtual bool evaluate() const = 0;
    void setInstigator(Entity *owner);
    virtual void destroy();

    Pickup *instigatorItem;

protected:
    Entity *instigator;
};

#endif
