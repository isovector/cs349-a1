#ifndef OBJECT_H
#define OBJECT_H

class Object;

#include "State.h"

class Object {
public:
    Object();

    void setState(State *state);
    void destroy();

    virtual void update(float delta);

    State *parentState;
    bool garbage;
};

#endif
