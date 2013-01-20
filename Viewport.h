#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "Constants.h"
#include "Math.h"

class Viewport {
public:
    Viewport();

    void setScreenSize(vec2 size);
    vec2 transform(vec2 input) const;

private:
    vec2 scale;
};

#endif
