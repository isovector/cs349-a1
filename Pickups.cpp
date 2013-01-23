#include "Explosion.h"
#include "Helicopter.h"
#include "Pickups.h"
#include "Projectile.h"
#include "Input.h"

BlinkPickup::BlinkPickup(vec2 pos) :
    Pickup(pos)
{
}

void BlinkPickup::drawUI(vec2 pos) const {
    GfxState gfx(0x00AAFF, 0);
    
    gfx.drawEllipse(pos, size, false);
}

void BlinkPickup::onPickup(Body* heli) {
    dynamic_cast<Helicopter*>(heli)->addPowerup(new BlinkPowerup(this));
    
    remove();
}

bool BlinkPowerup::evaluate() const {
    return true;
}

void BlinkPowerup::update(float delta) {
    static const size_t TELEPORT_ANIMS = 10;
    
    vec2 src = instigator->position;
    vec2 dir = (input.cursor - src) / TELEPORT_ANIMS;
    
    for (size_t i = 0; i < TELEPORT_ANIMS; i++)
        parentState->create(new Explosion(src + dir * (i + 1), 0.5f, 5 * i, 0x00AAFF));
    
    instigator->position = input.cursor;
    destroy();
}

BolderProjectile::BolderProjectile(Entity *owner, vec2 vel, CollisionGroup group) :
    Projectile(owner, vel, group)
{
    size = vec2(50, 50);
}
    
void BolderProjectile::contactNotify(Body *body) {
    body->destroy();
}

void BolderProjectile::draw() const {
    GfxState gfx(0x00FF00, 0);
    gfx.drawEllipse(position, size, true);
}

BolderPickup::BolderPickup(vec2 pos) :
    Pickup(pos)
{
}

void BolderPickup::drawUI(vec2 pos) const {
    GfxState gfx(0x00FF00, 0);
    
    gfx.drawEllipse(pos, size, false);
}

void BolderPickup::onPickup(Body* heli) {
    dynamic_cast<Helicopter*>(heli)->addPowerup(new BolderPowerup(this));
    
    remove();
}

bool BolderPowerup::evaluate() const {
    return true;
}

void BolderPowerup::update(float delta) {
    parentState->create(new BolderProjectile(instigator, vec2(400, 0), CG_FRIEND));
    destroy();
}


ShieldPickup::ShieldPickup(vec2 pos) :
    Pickup(pos)
{
}

void ShieldPickup::drawUI(vec2 pos) const {
    GfxState gfx(0x770077, 0);
    
    gfx.drawEllipse(pos, size, false);
}

void ShieldPickup::onPickup(Body* heli) {
    dynamic_cast<Helicopter*>(heli)->addPowerup(new ShieldPowerup(this));
    
    remove();
}

bool ShieldPowerup::evaluate() const {
    return true;
}

void ShieldPowerup::update(float delta) {
    parentState->create(new ShieldBody(dynamic_cast<Body*>(instigator)));
    destroy();
}

ShieldBody::ShieldBody(Body *instig) :
    Body(vec2(0, 0), vec2(50, 50), CG_FRIEND, false),
    instigator(instig),
    lifeTime(3.0f)
{
}

void ShieldBody::update(float delta) {
    if (instigator->garbage)
        destroy();
    
    if (instigator)
        position = instigator->position + vec2(-size.x / 4, -instigator->size.y);
    
    lifeTime -= delta;
    if (lifeTime <= 0.0f)
        destroy();
}

void ShieldBody::draw() const {
    GfxState gfx(0x770077, 0);
    gfx.drawEllipse(position, size, true);
}

void ShieldBody::contactNotify(Body *body) {
    if (dynamic_cast<Projectile*>(body)) {
        body->destroy();
    }
}
