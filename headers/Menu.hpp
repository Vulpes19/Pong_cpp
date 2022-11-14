#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

char	*ft_itoa(int n);

class Menu
{
public:
    Menu( void );
    ~Menu( void );
    void    writeText( SDL_Renderer*, const char*);
    void    mouseEvents( bool &, bool & );
    void    renderMenu( SDL_Renderer* );
    void    freeMenu( void );
private:
    TTF_Font	*font;
	SDL_Color	color;
	SDL_Texture	*textTexture;
	SDL_Rect dest;
    bool        hover_play;
    bool        hover_exit;
};

#endif
