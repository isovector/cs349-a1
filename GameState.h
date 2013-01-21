#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <list>
#include <set>

#include "State.h"
#include "Entity.h"

class GameState : public State {
public:
    GameState();
    
    virtual void update(float delta);
    virtual void draw() const;

    virtual void create(Object *obj);
    virtual void destroy(Object *obj);

    template<class T>
    T* getObjectOfType() {
        for (std::list<Object*>::iterator it = objects.begin(); it != objects.end(); ++it) {
            T* obj = dynamic_cast<T*>(*it);
            if (obj)
                return obj;
        }
        
        return NULL;
    }
    
private:
    float scrollSpeed;
    std::list<Object*> objects;
    std::set<Object*> destroyedObjects;
};

#endif
