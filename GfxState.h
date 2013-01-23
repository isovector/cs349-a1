#ifndef GFX_STATE_H
#define GFX_STATE_H

#include <cstring>
#include "a1.h"

class GfxState {
public:
    GfxState();
    GfxState(unsigned long fore, unsigned long back);

    void drawRect(vec2 pos, vec2 size, bool fill = true) const;
    void drawEllipse(vec2 pos, vec2 size, bool fill = true) const;
    void drawText(vec2 pos, const char *str) const;

    void change(unsigned long fore, unsigned long back);
    
    ~GfxState();
    
private:
    void updateValues(XGCValues *vals = NULL);

    XGCValues values;
};

#endif
