#include "a1.h"
#include "SplashState.h"
#include "Input.h"
#include "GfxState.h"

void SplashState::update(float delta) {
    if (input.keyPress(XK_f))
        states.pop_back();
}

void SplashState::draw() const {
    GfxState gfx(0, 0);
    gfx.drawRect(vec2(0, 0), vec2(SCREEN_WIDTH, SCREEN_HEIGHT));
    
    gfx.change(0xFF0000, 0);
    gfx.drawText(vec2(15, 15), "Alexander Maguire");
    gfx.drawText(vec2(15, 29), "20396195");
    gfx.drawText(vec2(SCREEN_WIDTH, SCREEN_HEIGHT) / 2, "Press F to play!");
    
    gfx.drawText(vec2(500, 15), "Use WASD to move!");
    gfx.drawText(vec2(500, 29), "Press Space to shoot!");
    gfx.drawText(vec2(500, 43), "Use E to use powerups!");
    
    gfx.drawText(vec2(25, 420), "Powerups:");
    
    gfx.drawText(vec2(50, 440), "Teleport");
    
    gfx.change(0xFF00FF, 0);
    gfx.drawEllipse(vec2(25, 430), vec2(20, 20), false);
}


void SplashState::create(Object *obj) {
}

void SplashState::destroy(Object *obj) {
}
