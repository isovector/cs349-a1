#include "GameState.h"

#include "Body.h"

#include "Helicopter.h"
#include "DifficultyProvider.h"

#include <vector>
#include <iostream>
using namespace std;

typedef std::list<Object*>::iterator ObjectIterator;
typedef std::list<Object*>::const_iterator ObjectConstIterator;
typedef std::set<Object*>::iterator DestroyObjectIterator;

GameState::GameState() :
    scrollSpeed(200.0f)
{
    create(new Helicopter(30, 15));
    create(new DifficultyProvider());
}

void GameState::update(float delta) {
    for (DestroyObjectIterator it = destroyedObjects.begin(); it != destroyedObjects.end(); ++it) {
        objects.remove(*it);
        delete *it;
    }
    destroyedObjects.clear();
    
    vector<Body*> bodies;
    
    for (ObjectIterator it = objects.begin(); it != objects.end(); ++it) {
        Object *obj = *it;
        obj->update(delta);
        
        Entity *entity = dynamic_cast<Entity*>(obj);
        if (entity && entity->autoScrolls)
            entity->position.x -= scrollSpeed * delta;
        
        Body *body = dynamic_cast<Body*>(obj);
        if (body)
            bodies.push_back(body);
    }
    
    for (size_t a = 0; a < bodies.size(); ++a)
        for (size_t b = a + 1; b < bodies.size(); ++b) {
            Body *bodyA = bodies[a], *bodyB = bodies[b];
            
            if (bodyA->collisionGroup == bodyB->collisionGroup
                && bodyA->collisionGroup != 0)
                continue;
            
            rect2 rectA = bodyA->getRect();
            rect2 rectB = bodyB->getRect();
            
            if (rectA.intersects(rectB)) {
                bodyA->contactNotify(bodyB);
                bodyB->contactNotify(bodyA);
            }
        }
}

void GameState::draw() const {
    XSetForeground(display, gc, BlackPixel(display, 0));
    XFillRectangle(display, buffer, gc, 0, 0, 600, 400);
    XSetForeground(display, gc, WhitePixel(display, 0));
    
    for (ObjectConstIterator it = objects.begin(); it != objects.end(); ++it) {
        Entity *entity = dynamic_cast<Entity*>(*it);
        if (entity)
            entity->draw();
    }
    
  XCopyArea(display, buffer, win, gc, 0, 0, 600, 400, 0, 0);
}

void GameState::create(Object *obj) {
    objects.push_back(obj);
    obj->setState(this);
}

void GameState::destroy(Object *obj) {
    destroyedObjects.insert(obj);
}
