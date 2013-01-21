#ifndef SPLASH_STATE_H
#define SPLASH_STATE_H

#include "State.h"

class SplashState : public State {
public:
    virtual void update(float delta);
    virtual void draw() const;

    virtual void create(Object *obj);
    virtual void destroy(Object *obj);
};

#endif
