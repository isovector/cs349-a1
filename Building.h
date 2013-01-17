#ifndef BUILDING_H
#define BUILDING_H

#include "Body.h"

class Building : public Body {
public:
    Building(float width, float height);

    virtual void update(float delta);
    virtual void draw() const;
    virtual void contactNotify(Body *body);
};

#endif
