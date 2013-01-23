#include "a1.h"
#include "ScoreState.h"
#include "Input.h"
#include "GfxState.h"

#include <cstdio>
using namespace std;

ScoreState::ScoreState(int scor) : 
    score(scor) 
{
}

void ScoreState::update(float delta) {
    if (input.keyPress(XK_f))
        states.pop_back();
}

void ScoreState::draw() const {
    char itoabuffer[24];
    
    sprintf(itoabuffer, "%d", score);
    
    GfxState gfx(0, 0);
    gfx.drawRect(vec2(0, 0), vec2(SCREEN_WIDTH, SCREEN_HEIGHT));
    
    gfx.change(0xFF0000, 0);
    gfx.drawText(vec2(SCREEN_WIDTH, SCREEN_HEIGHT) / 2, "YOU DIED");
    gfx.drawText(vec2(SCREEN_WIDTH, SCREEN_HEIGHT) / 2 + vec2(0, 20), "Press F to play again!");
    
    gfx.drawText(vec2(500, 15), "Score:");
    gfx.drawText(vec2(540, 15), itoabuffer);
}


void ScoreState::create(Object *obj) {
}

void ScoreState::destroy(Object *obj) {
}
