#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <list>

#include "State.h"
#include "Entity.h"

class GameState : public State {
public:
    GameState();
    
    virtual void update(float delta);
    virtual void draw() const;

    virtual void create(Object *obj);
    virtual void destroy(Object *obj);
    
private:
    float scrollSpeed;
    std::list<Object*> objects;
    std::list<Object*> destroyedObjects;
};

#endif
