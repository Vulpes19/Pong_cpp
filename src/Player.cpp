#include "Player.hpp"

Player::Player( void )
{
    posX = 10.0f;
    posY = 300.0f;
    score = 0;
    speed = 30.0f;
}

Player::~Player( void )
{
}

void    Player::drawRacket( SDL_Renderer *renderer )
{
    racket.h = 200;
    racket.w = 35;
    racket.x = posX;
    racket.y = posY;

    SDL_RenderDrawRect( renderer, &racket );
    SDL_RenderFillRect( renderer, &racket );
}

void    Player::setPosY( float y )
{
    if ( y < 0 )
    {
        posY = 0;
        return ;
    }
    if ( y > 700 )
    {
        posY = 700;
        return ;
    }
    posY = y;
}