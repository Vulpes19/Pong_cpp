#include "Player.hpp"

Player::Player( void )
{
    std::cout << "Player is created" << std::endl;
    posX = 10.0f;
    posY = 300.0f;
    score = 0;
    speed = 27.0f;
}

Player::~Player( void )
{
    std::cout << "Player is destoryed" << std::endl;
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
