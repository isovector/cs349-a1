#ifndef INPUT_H
#define INPUT_H

#define XK_MISCELLANY
#include <X11/keysymdef.h>

#include <set>
#include <map>

#include "a1.h"
#include "Object.h"

class Input : public Object {
public:
    Input();

    virtual void update(float elapsed);
    bool keyDown(unsigned int keysym);
    bool keyPress(unsigned int keysym);

private:
    std::set<int> keyPresses;
    std::map<int, bool> keyState;
};

extern Input input;

#endif
