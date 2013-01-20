#ifndef GFX_STATE_H
#define GFX_STATE_H

#include "a1.h"

class GfxState {
public:
    GfxState();
    GfxState(unsigned long fore, unsigned long back);

    void drawRect(vec2 pos, vec2 size) const;
    void drawEllipse(vec2 pos, vec2 size) const;

    void change(unsigned long fore, unsigned long back);
    
    ~GfxState();
    
private:
    void updateValues(XGCValues *vals = NULL);

    XGCValues values;
};

#endif
