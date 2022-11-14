#ifndef PAUSE_HPP
#define PAUSE_HPP

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

class Pause
{
    public:
    Pause( void );
    ~Pause( void );
    void    writeText( SDL_Renderer*, const char*);
    void    pauseEvents( bool &, bool & );
    void    renderMenu( SDL_Renderer* );
private:
    TTF_Font	*font;
	SDL_Color	color;
	SDL_Texture	*textTexture;
	SDL_Rect dest;
    bool    hover;
};

#endif