#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Ball.hpp"
#include "Score.hpp"

class Window
{
	public:
		Window( unsigned int, unsigned int );
		~Window( void );
		int		createWindow( void );
		void	handleEvents( void );
		void	gameLoop( void );
		void	render( void );
	private:
		SDL_Window		*window;
		SDL_Renderer	*renderer;
		Player			player;
		Enemy			enemy;
		Score			score;
		Ball			ball;
		bool			running;
		SDL_Event		event;
		unsigned int	width;
		unsigned int	height;
};

#endif