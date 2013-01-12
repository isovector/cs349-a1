#include "Object.h"

Object::Object() :
    garbage(false)
{
}

void Object::setState(State *own)
{
    parentState = own;
}

void Object::destroy()
{
    garbage = true;
    parentState->destroy(this);
}

void Object::update(float delta) {
}


