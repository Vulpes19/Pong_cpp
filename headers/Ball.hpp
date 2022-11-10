#ifndef BALL_HPP
#define BALL_HPP

#include <iostream>
#include <SDL.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Score.hpp"

class Ball
{
	public:
		Ball( void );
		~Ball( void );
		void	drawBall( SDL_Renderer* );
		void	updateBall( Player&, Enemy&, Score& );
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