#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <SDL.h>

class Window
{
	public:
		Window( unsigned int, unsigned int );
		~Window( void );
		int		createWindow( void );
		void	handleEvents( void );
	private:
		SDL_Window		*window;
		SDL_Renderer	*renderer;
		bool			running;
		SDL_Event		event;
		unsigned int	width;
		unsigned int	height;
};

#endif