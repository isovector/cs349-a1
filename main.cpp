#include "a1.h"
#include "GameState.h"
#include "Input.h"
#include <iostream>
using namespace std;

Display *display;
Window win;
GC gc;

State *state;
Input input;

Pixmap buffer;

void initialize_window() {
    display = XOpenDisplay(":0");
    win = XCreateSimpleWindow(display, RootWindow(display, 0), 10, 10, 600, 400, 1, BlackPixel(display, 0), WhitePixel(display, 0));
    
    XMapWindow(display, win);
    
    int screen = XDefaultScreen(display);
    gc = XCreateGC(display, win, 0, NULL);
    
    XClassHint *hint = XAllocClassHint();
    hint->res_class = "CS349";
    hint->res_name = "A1";
    XSetClassHint(display, win, hint);
    
    XSetForeground(display, gc, WhitePixel(display, 0));
    XSetBackground(display, gc, BlackPixel(display, 0));
    XSetFillStyle(display, gc, FillSolid);
    XSetLineAttributes(display, gc, 2, LineSolid, CapRound, JoinRound);
    
    XSync(display, false);
    
    XSelectInput(display, win, ExposureMask | ButtonPressMask | KeyPressMask | KeyReleaseMask);
}

void initialize_buffers(size_t w, size_t h) {
    buffer = XCreatePixmap(display, win, w, h, 24);
}

int main() {
    initialize_window();
    initialize_buffers(600, 400);
    
    struct timespec ts_start;
    struct timespec ts_end;

	clock_gettime(CLOCK_MONOTONIC, &ts_start);
    
    state = new GameState;
    while (state) {
        float delta = static_cast<float>(SLEEP_DURATION) / 1000000.0f;
        
        clock_gettime(CLOCK_MONOTONIC, &ts_start);
        
        input.update(delta);
        state->update(delta);
        state->draw();
        
        XSync(display, false);
        clock_gettime(CLOCK_MONOTONIC, &ts_end);
        
        size_t duration = (ts_end.tv_nsec - ts_start.tv_nsec) / 1000;
        
        // sometimes when the window is on a differnt workspace, duration will underflow
        usleep(min(SLEEP_DURATION - duration, SLEEP_DURATION));
    }
    delete state;
    
    XCloseDisplay(display);
}