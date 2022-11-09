#ifndef BALL_HPP
#define BALL_HPP

#include <iostream>
#include <SDL.h>

class Ball
{
	public:
		Ball( void );
		~Ball( void );
		void	drawBall( SDL_Renderer*, int, int );
	private:
		float	posX;
		float	posY;
		float	dirX;
		float	dirY;
		float	speed;
		int		size;
		SDL_Rect	_ball;
};

#endif