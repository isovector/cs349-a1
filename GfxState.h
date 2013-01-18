#ifndef GFX_STATE_H
#define GFX_STATE_H

#include "a1.h"

class _GfxState {
public:
    _GfxState();
    _GfxState(unsigned long fore, unsigned long back);
    
    ~_GfxState();
    
private:
    void updateValues(XGCValues *vals = NULL);

    XGCValues values;
};

#define GfxState _GfxState __gfxState

#endif
