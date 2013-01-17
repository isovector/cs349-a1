#ifndef A1_H
#define A1_H

#include <X11/Xlib.h>
#include <X11/X.h>
#include <X11/Xutil.h>

#include <time.h>
#include <unistd.h>

#include "Math.h"

extern Display *display;
extern Window win;
extern GC gc;
extern Pixmap buffer;

const size_t FRAMES_PER_SECOND = 60;
const size_t SLEEP_DURATION = 1000000 / FRAMES_PER_SECOND;

#endif
