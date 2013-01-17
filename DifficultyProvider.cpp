#include "DifficultyProvider.h"

#include "Building.h"

#include <cstdlib>
using namespace std;

DifficultyProvider::DifficultyProvider() :
    nextBuildingTimer(1.0f)
{
}

void DifficultyProvider::update(float delta) {
    nextBuildingTimer -= delta;
    if (nextBuildingTimer > 0.0f)
        return;
    
    unsigned int width = rand() % 80 + 10;
    unsigned int height = rand() % 300 + 50;
    
    parentState->create(new Building(width, height));
    
    nextBuildingTimer = (rand() % 100) / 100.0f;
}
