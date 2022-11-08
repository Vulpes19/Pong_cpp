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
		void	setPlayerScore( unsigned int p ) { playerScore = p; };
		void	setEnemyScore( unsigned int	e ) { enemyScore = e; };
	private:
		unsigned int playerScore;
		unsigned int enemyScore;
		TTF_Font	*font;
		SDL_Color	color;
		SDL_Surface	*text;
		SDL_Texture	*textTexture;
};

#endif