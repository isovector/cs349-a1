#ifndef A1_H
#define A1_H

#include <X11/Xlib.h>
#include <X11/X.h>
#include <X11/Xutil.h>

#include <time.h>
#include <unistd.h>

#include "Math.h"
#include "Constants.h"
#include "Viewport.h"

extern Display *display;
extern Window win;
extern GC gc;
extern Pixmap buffer;
extern Viewport viewport;

void initialize_buffers(size_t w, size_t h, bool free = true);

#endif
