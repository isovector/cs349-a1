#include "Input.h"

#include <iostream>
using namespace std;

void Input::update(float) {
    keyPresses.clear();
    
    while (XPending(display)) {
        XEvent ev;
        XNextEvent(display, &ev);
        
        unsigned int key = XLookupKeysym(&ev.xkey, 0);
        switch (ev.type) {
            case KeyPress: {
                if (!keyState[key])
                    keyPresses.insert(key);
                keyState[key] = true;
            } break;
            
            case KeyRelease: {
                if (XEventsQueued(display, QueuedAfterReading)) {
                    XEvent nev;
                    XPeekEvent(display, &nev);

                    if (!(nev.type == KeyPress && nev.xkey.time == ev.xkey.time
                        && nev.xkey.keycode == ev.xkey.keycode)) {
                        keyState[key] = false;
                    }
                } else {
                    keyState[key] = false;
                }
            } break;
            
            case MotionNotify: {
                cursor.x = ev.xmotion.x;
                cursor.y = ev.xmotion.y;
            } break;
            
            case ConfigureNotify: {
                initialize_buffers(ev.xconfigure.width, ev.xconfigure.height);
            } break;
        }
    }
}

bool Input::keyDown(unsigned int keysym) {
    return keyState[keysym];
}

bool Input::keyPress(unsigned int keysym) {
    return keyPresses.count(keysym) != 0;
}
