#include "Input.h"

#include <iostream>
using namespace std;

Input::Input() {
}

void Input::update(float) {
    keyPresses.clear();
    
    while (XPending(display))
    {
        XEvent ev;
        XNextEvent(display, &ev);
        
        unsigned int key = XLookupKeysym(&ev.xkey, 0);
        switch (ev.type) {
            case KeyPress: {
                keyPresses.insert(key);
                keyState[key] = true;
            } break;
            
            case KeyRelease: {
                keyState[key] = false;
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
