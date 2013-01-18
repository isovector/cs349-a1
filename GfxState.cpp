#include "GfxState.h"

#include <iostream>
using namespace std;

_GfxState::_GfxState() {
    updateValues();
}

_GfxState::_GfxState(unsigned long fore, unsigned long back) {
    updateValues();
    
    if (fore != values.foreground)
        XSetForeground(display, gc, fore);
    
    if (back != values.background)
        XSetForeground(display, gc, back);
}
    
_GfxState::~_GfxState() {
    XGCValues newValues;
    updateValues(&newValues);
    
    if (newValues.foreground != values.foreground)
        XSetForeground(display, gc, values.foreground);
    
    if (newValues.background != values.background)
        XSetForeground(display, gc, values.background);
}

void _GfxState::updateValues(XGCValues *vals) {
    if (vals == NULL)
        vals = &values;
    
    XGetGCValues(display, gc, GCForeground | GCBackground, vals);
}
