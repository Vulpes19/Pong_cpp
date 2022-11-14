#include "Ball.hpp"
#include <tgmath.h>

Ball::Ball( void )
{
    dirX = -1.0f;
    dirY = 0.0f;
    posX = 620.0f;
    posY = 420.0f;
    size = 8;
    speed = 1.0f;
}

Ball::~Ball( void )
{
}

void    Ball::drawBall( SDL_Renderer *renderer )
{
    int x = static_cast<int>(posX);
    int y = static_cast<int>(posY);

    _ball = { x, y, 10, 10};
    SDL_RenderDrawRect( renderer, &_ball );
    SDL_RenderFillRect( renderer, &_ball );
}

void    Ball::updateBall( Player &player,  Enemy &enemy, Score &score )
{
    SDL_Rect    playerRacket = player.getRacket();
    SDL_Rect    enemyRacket = enemy.getRacket();
    posX += dirX * speed;
    posY += dirY * speed;
    if ( SDL_HasIntersection( &playerRacket, &_ball ) )
    {
        float changeDir = ((posY - player.getPosY()) / 200) - 0.5f;
        dirX = fabs(dirX);
        dirY = changeDir;
    }
    if ( SDL_HasIntersection( &enemyRacket, &_ball ) )
    {
        float changeDir = ((posY - enemy.getPosY()) / 200) - 0.5f;
        dirX = -fabs(dirX); //absolute value forced to be negative
        dirY = changeDir;
    }
    if ( posX < 0 )
    {
        score.incrementEnemyScore();
        posX = 620;
        posY = 450;
        dirX = fabs(dirX);
        dirY = 0.0f;
    }
    if ( posX > 1240 )
    {
        score.incrementPlayerScore();
        posX = 620;
        posY = 450;
        dirX = -fabs(dirX);
        dirY = 0.0f;
    }
    if ( posY > 900)
        dirY = -fabs(dirY);
    if (posY < 0)
        dirY = fabs(dirY);
}