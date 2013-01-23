#ifndef OBJECT_H
#define OBJECT_H

class Object;

#include "State.h"

class Object {
public:
    Object();

    virtual void setState(State *state);
    virtual void destroy();

    virtual void update(float delta);

    State *parentState;
    bool garbage;
};

#endif
