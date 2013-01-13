#ifndef BUILDING_H
#define BUILDING_H

#include "Entity.h"

class Building : public Entity {
public:
    Building(float width, float height);

    virtual void update(float delta);
    virtual void draw() const;

private:
    vec2 size;
};

#endif
