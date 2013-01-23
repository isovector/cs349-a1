#include "DifficultyProvider.h"

#include "Building.h"
#include "Turret.h"
#include "Pickups.h"

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
    
    unsigned int width = rand() % (SCREEN_WIDTH / 6) + 10;
    unsigned int height = rand() % (SCREEN_HEIGHT / 3 * 2) + 50;
    bool topAligned = rand() % 2 == 0;
    
    parentState->create(new Building(width, height, topAligned));
    if (rand() % 100 > 60)
        parentState->create(new Turret(vec2(SCREEN_WIDTH, SCREEN_HEIGHT - height - 25)));
    
    if (rand() % 100 > 80)
        parentState->create(new BlinkPickup(vec2(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT)));
    
    nextBuildingTimer = (rand() % 100) / 100.0f + 0.3f;
}
