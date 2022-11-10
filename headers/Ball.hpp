#ifndef BALL_HPP
#define BALL_HPP

#include <iostream>
#include <SDL.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Score.hpp"

/* Ball Class */

class Ball
{
	public:
		Ball( void );
		~Ball( void );
		void	drawBall( SDL_Renderer* ); //displays the ball on the screen
		void	updateBall( Player&, Enemy&, Score& ); //checks for collision and updates x and y axis
		float	getPosX( void ) { return (posX); };
		float	getPosY( void ) { return (posY); };
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