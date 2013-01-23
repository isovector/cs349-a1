#include "a1.h"
#include "SplashState.h"
#include "ScoreState.h"
#include "GameState.h"
#include "Input.h"

#include <iostream>
using namespace std;

Display *display;
Window win;
GC gc;

vector<State*> states;
Input input;

Viewport viewport;
Pixmap buffer;

int score;

size_t screen_width = SCREEN_WIDTH, screen_height = SCREEN_HEIGHT;

void initialize_window() {
    display = XOpenDisplay(":0");
    win = XCreateSimpleWindow(display, RootWindow(display, 0), 10, 10, SCREEN_WIDTH, SCREEN_HEIGHT, 1, BlackPixel(display, 0), WhitePixel(display, 0));
    
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
    
    XSelectInput(display, win, ExposureMask | ButtonPressMask | KeyPressMask | KeyReleaseMask | PointerMotionMask | StructureNotifyMask);
    
    // hide the mouse cursor
    Cursor invisibleCursor;
    Pixmap bitmapNoData;
    XColor black;
    static char noData[] = { 0,0,0,0,0,0,0,0 };
    black.red = black.green = black.blue = 0;

    bitmapNoData = XCreateBitmapFromData(display, win, noData, 8, 8);
    invisibleCursor = XCreatePixmapCursor(display, bitmapNoData, bitmapNoData, 
                                         &black, &black, 0, 0);
    XDefineCursor(display,win, invisibleCursor);
    XFreeCursor(display, invisibleCursor);
}

void initialize_buffers(size_t w, size_t h, bool free) {
    if (free)
        XFreePixmap(display, buffer);
    
    buffer = XCreatePixmap(display, win, w, h, 24);
    
    screen_width = w;
    screen_height = h;
    viewport.setScreenSize(vec2(w, h));
}

int main() {
    initialize_window();
    initialize_buffers(SCREEN_WIDTH, SCREEN_HEIGHT, false);
    
    struct timespec ts_start;
    struct timespec ts_end;

	clock_gettime(CLOCK_MONOTONIC, &ts_start);
    
    float timeScale = 1.0f;
    
    states.push_back(new GameState);
    states.push_back(new SplashState);
    while (states.size()) {
        State *state = states.back();
        
        try {
            float delta = static_cast<float>(SLEEP_DURATION) / 1000000.0f * timeScale;
            
            clock_gettime(CLOCK_MONOTONIC, &ts_start);
            
            size_t numStates = states.size();
            
            input.update(delta);
            state->update(delta);
            state->draw();
            
            XCopyArea(display, buffer, win, gc, 0, 0, screen_width, screen_height, 0, 0);

            XSync(display, false);
            
            if (states.size() < numStates)
                delete state;
            
                
            #define TIMESCALER(k) if (input.keyPress(XK_##k)) timeScale = 0.1f * k;
            TIMESCALER(1)
            TIMESCALER(2)
            TIMESCALER(3)
            TIMESCALER(4)
            TIMESCALER(5)
            TIMESCALER(6)
            TIMESCALER(7)
            TIMESCALER(8)
            TIMESCALER(9)
            if (input.keyPress(XK_0)) timeScale = 1.0f;
            #undef TIMESCALER
            
            clock_gettime(CLOCK_MONOTONIC, &ts_end);
            
            size_t duration = (ts_end.tv_nsec - ts_start.tv_nsec) / 1000;
            
            // sometimes when the window is on a differnt workspace, duration will underflow
            usleep(min(SLEEP_DURATION - duration, SLEEP_DURATION));
        } catch (int score) {
            delete state;
            states.pop_back();
            
            states.push_back(new GameState);
            states.push_back(new ScoreState(score));
            
            cout << "Score was " << score << endl;
        }
    }
    
    XCloseDisplay(display);
}

void loseGame() {
    throw score;
}
