#ifndef SCORE_STATE_H
#define SCORE_STATE_H

#include "State.h"

class ScoreState : public State {
public:
    ScoreState(int score);

    virtual void update(float delta);
    virtual void draw() const;

    virtual void create(Object *obj);
    virtual void destroy(Object *obj);

private:
    int score;
};

#endif
