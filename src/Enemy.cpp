#include "Enemy.hpp"
#include "Ball.hpp"

Enemy::Enemy( void )
{
    posX = 1190.0f;
    posY = 300.0f;
    score = 0;
    speed = 27.0f;
}

Enemy::~Enemy( void )
{
}

void    Enemy::drawRacket( SDL_Renderer *renderer )
{
    racket.h = 200;
    racket.w = 35;
    racket.x = posX;
    racket.y = posY;

    SDL_RenderDrawRect( renderer, &racket );
    SDL_RenderFillRect( renderer, &racket );
}

void    Enemy::updateAI( Ball &ball )
{
    if ( posY > 700 )
        posY = 700;
    if ( posY < 0 )
        posY = 0;
    if ( ball.getPosY() > posY + 100 && rand() % 2 == 0)
        posY++;
    else if ( ball.getPosY() < posY + 100 && rand() % 2 == 0)
        posY--;
}
