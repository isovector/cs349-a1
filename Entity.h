#ifndef ENTITY_H
#define ENTITY_H

#include "a1.h"
#include "Object.h"

class Entity : public Object {
public:
    Entity(vec2 pos, bool scrolls = true);

    virtual void draw() const;

    vec2 position;
    bool autoScrolls;
};

#endif
