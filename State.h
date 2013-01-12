#ifndef STATE_H
#define STATE_H

#include "a1.h"

class State;

#include "Object.h"

class State {
public:
    virtual void update(float delta) = 0;
    virtual void draw() const = 0;

    virtual void create(Object *obj) = 0;
    virtual void destroy(Object *obj) = 0;
};

#endif
