#ifndef PICKUPS_H
#define PICKUPS_H

#include "Pickup.h"
#include "Powerup.h"
#include "Projectile.h"

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

class BolderProjectile : public Projectile {
public:
    BolderProjectile(Entity *owner, vec2 vel, CollisionGroup group);
    
    virtual void contactNotify(Body *body);
    virtual void draw() const;
};

class BolderPickup : public Pickup {
public:
    BolderPickup(vec2 pos);
    
    virtual void drawUI(vec2 pos) const;
    virtual void onPickup(Body* heli);
};

class BolderPowerup : public Powerup {
public:
    BolderPowerup(Pickup *item) : Powerup(item) { }

    virtual bool evaluate() const;
    virtual void update(float delta);
};

class ShieldPickup : public Pickup {
public:
    ShieldPickup(vec2 pos);
    
    virtual void drawUI(vec2 pos) const;
    virtual void onPickup(Body* heli);
};

class ShieldPowerup : public Powerup {
public:
    ShieldPowerup(Pickup *item) : Powerup(item) { }

    virtual bool evaluate() const;
    virtual void update(float delta);
};

class ShieldBody : public Body {
public:
    ShieldBody(Body *instigator);

    virtual void update(float delta);
    virtual void draw() const;
    virtual void contactNotify(Body *body);

private:
    Body *instigator;
    float lifeTime;
};


#endif
