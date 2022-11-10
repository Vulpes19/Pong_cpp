#ifndef SCORE_HPP
#define SCORE_HPP

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

char	*ft_itoa(int n);

class Score
{
	public:
		Score( void );
		~Score( void );
		void	displayScore( SDL_Renderer* );
		void	incrementPlayerScore( void ) { playerScore++; };
		void	incrementEnemyScore( void ) { enemyScore++; };
	private:
		unsigned int playerScore;
		unsigned int enemyScore;
		TTF_Font	*font;
		SDL_Color	color;
		SDL_Texture	*textTexture;
		SDL_Rect dest;
};

#endif