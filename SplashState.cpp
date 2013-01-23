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
    gfx.drawText(vec2(500, 57), "Aim with the mouse!");
    gfx.drawText(vec2(500, 71), "Set speed with 1-9!");
    
    gfx.drawText(vec2(25, 420), "Powerups:");
    
    gfx.drawText(vec2(50, 445), "Teleport");
    gfx.drawText(vec2(150, 445), "Boulder");
    gfx.drawText(vec2(250, 445), "Shield");
    
    gfx.change(0x00AAFF, 0);
    gfx.drawEllipse(vec2(25, 430), vec2(20, 20), false);
    gfx.change(0x00FF00, 0);
    gfx.drawEllipse(vec2(125, 430), vec2(20, 20), false);
    gfx.change(0x770077, 0);
    gfx.drawEllipse(vec2(225, 430), vec2(20, 20), false);
}


void SplashState::create(Object *obj) {
}

void SplashState::destroy(Object *obj) {
}
