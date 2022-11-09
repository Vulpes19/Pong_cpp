#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL.h>
#include <iostream>

class Player
{
    public:
        Player( void );
        ~Player( void );
        void    drawRacket( SDL_Renderer *renderer );
        float   getPosX( void ) { return (posX); };
        float   getPosY( void ) { return (posY); };
        int     getSpeed( void ) { return (speed); };
        void    setPosX( float x ) { posX = x; };
        void    setPosY( float y );
        void    setSpeed( float s) { speed = s; };
    private:
        SDL_Rect    racket;
        unsigned int score;
        float posX;
        float posY;
        float     speed;
};

#endif