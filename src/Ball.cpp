#include "Ball.hpp"

Ball::Ball( void )
{
    std::cout << "Ball is created" << std::endl;
    dirX = -1.0f;
    dirY = 0.0f;
    size = 8;
    speed = 2.0f;
}

Ball::~Ball( void )
{
    std::cout << "Ball is destroyed" << std::endl;
}

void    Ball::drawBall( SDL_Renderer *renderer, int w, int h )
{
    _ball = { w / 2, h / 2, 8, 8};
    SDL_RenderDrawRect( renderer, &_ball );
    SDL_RenderFillRect( renderer, &_ball );
}