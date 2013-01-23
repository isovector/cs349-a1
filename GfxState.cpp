#include "GfxState.h"

#include <iostream>
using namespace std;

GfxState::GfxState() {
    updateValues();
}

GfxState::GfxState(unsigned long fore, unsigned long back) {
    updateValues();
    change(fore, back);
}
    
GfxState::~GfxState() {
    XGCValues newValues;
    updateValues(&newValues);
    
    if (newValues.foreground != values.foreground)
        XSetForeground(display, gc, values.foreground);
    
    if (newValues.background != values.background)
        XSetForeground(display, gc, values.background);
}

void GfxState::updateValues(XGCValues *vals) {
    if (vals == NULL)
        vals = &values;
    
    XGetGCValues(display, gc, GCForeground | GCBackground, vals);
}

void GfxState::change(unsigned long fore, unsigned long back) {
    if (fore != values.foreground)
        XSetForeground(display, gc, fore);
    
    if (back != values.background)
        XSetForeground(display, gc, back);
}

void GfxState::drawRect(vec2 pos, vec2 size, bool fill) const {
    pos = viewport.transform(pos);
    size = viewport.transform(size);
    
    if (fill)
        XFillRectangle(display, buffer, gc, UNPACKI(pos), UNPACKI(size));
    else
        XDrawRectangle(display, buffer, gc, UNPACKI(pos), UNPACKI(size));
}

void GfxState::drawEllipse(vec2 pos, vec2 size, bool fill) const {
    pos = viewport.transform(pos);
    size = viewport.transform(size);
    if (fill)
        XFillArc(display, buffer, gc, UNPACKI(pos), UNPACKI(size), 0, 9999999);
    else
        XDrawArc(display, buffer, gc, UNPACKI(pos), UNPACKI(size), 0, 9999999);
}

void GfxState::drawText(vec2 pos, const char *str) const {
    XDrawImageString(display, buffer, gc, UNPACKI(pos), str, strlen(str));
}
