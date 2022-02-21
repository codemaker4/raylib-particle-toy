#include <stdlib.h>
#include <math.h>
#include "raylib.h"

class Particle
{
private:
    Vector2 pos;
    Vector2 vel;
    Color color;

    float getDist(Vector2 pos);
    Vector2 getNormal(Vector2 otherPos);
public:
    Particle(int screenWidth, int screenHeight);
    Particle(Vector2 pos, Vector2 vel, Color color);
    // ~Particle();

    void attract(Vector2 posToAttract, float multiplier);
    void doFriction(float amount);
    void move(int screenWidth, int screenHeight);
    void drawPixel();
};

Particle::Particle(int screenWidth, int screenHeight)
{
    pos.x = GetRandomValue(0, screenWidth-1);
    pos.y = GetRandomValue(0, screenHeight-1);
    vel.x = GetRandomValue(-100, 100) / 100.f;
    vel.y = GetRandomValue(-100, 100) / 100.f;
    // color = (Color){GetRandomValue(0,255),GetRandomValue(0,255),GetRandomValue(0,255),255};
    color = (Color){0,0,0,100};
}

Particle::Particle(Vector2 _pos, Vector2 _vel, Color _color)
{
    pos = _pos;
    vel = _vel;
    color = _color;
}

float Particle::getDist(Vector2 otherPos) {
    const float dx = pos.x - otherPos.x;
    const float dy = pos.y - otherPos.y;
    return sqrt((dx*dx) + (dy*dy));
}

Vector2 Particle::getNormal(Vector2 otherPos) {
    float dist = getDist(otherPos);
    if (dist == 0.0f) dist = 1;
    const float dx = pos.x - otherPos.x;
    const float dy = pos.y - otherPos.y;
    Vector2 normal = (Vector2){dx*(1/dist), dy*(1/dist)};
    return normal;
}


void Particle::attract(Vector2 posToAttract, float multiplier)
{
    float dist = fmax(getDist(posToAttract),0.5);
    Vector2 normal = getNormal(posToAttract);

    vel.x -= normal.x/dist;
    vel.y -= normal.y/dist;
}

void Particle::doFriction(float amount) {
    vel.x *= amount;
    vel.y *= amount;
}

void Particle::move(int screenWidth, int screenHeight) {
    pos.x += vel.x;
    pos.y += vel.y;
    if (pos.x < 0)
        pos.x += screenWidth;
    if (pos.x >= screenWidth)
        pos.x -= screenWidth;
    if (pos.y < 0)
        pos.y += screenHeight;
    if (pos.y >= screenHeight)
        pos.y -= screenHeight;
}

void Particle::drawPixel() {
    DrawPixelV(pos, color);
}

