#ifndef DIFFICULTY_PROVIDER_H
#define DIFFICULTY_PROVIDER_H

#include "Object.h"

class DifficultyProvider : public Object {
public:
    DifficultyProvider();

    virtual void update(float elapsed);

private:
    float nextBuildingTimer;
};

#endif
