#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <SDL.h>

class   Enemy
{
	public:
        Enemy( void );
        ~Enemy( void );
        void    drawRacket( SDL_Renderer *renderer );
        float   getPosX( void ) { return (posX); };
        float   getPosY( void ) { return (posY); };
        int     getSpeed( void ) { return (speed); };
        SDL_Rect getRacket( void )  { return (racket); };
        void    setPosX( float x ) { posX = x; };
        void    setPosY( float y ) { posY = y; };
    private:
        SDL_Rect    racket;
        unsigned int score;
        float posX;
        float posY;
        float     speed;
};

#endif