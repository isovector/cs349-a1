#ifndef ENTITY_H
#define ENTITY_H

#include "a1.h"
#include "Object.h"

class Entity : public Object {
public:
    Entity(vec2 pos);

    virtual void draw() const;

    vec2 position;
};

#endif
