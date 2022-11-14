#include "Score.hpp"
#include <string.h>

Score::Score( void )
{
	playerScore = 0;
	enemyScore = 0;
	color = {0, 255, 255, 255};
	dest = { 570, 10, 100, 50 };
	if ( TTF_Init() < 0 )
	{
		std::cerr << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
		return ;
	}
	font = TTF_OpenFont("/Users/asus/Documents/Pong_cpp/assets/slkscr.ttf", 32);
	if ( !font )
	{
		std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
		return ;    
	}
}

Score::~Score( void )
{
	TTF_CloseFont( font );
	TTF_Quit();
}

void	Score::displayScore( SDL_Renderer *renderer )
{
	char 	*str1 = ft_itoa(playerScore);
	char 	*tmp = ft_itoa(enemyScore);
	char 	*tmp2 = strdup(" - ");
	char 	*str2 = strcat( tmp2, tmp );
	char	*toDisplay = strcat( str1, str2 );
	SDL_Surface	*text = nullptr;
	textTexture = nullptr;

	free(str1);
	free(tmp);
	free(tmp2);
	text = TTF_RenderText_Solid( font, toDisplay, color );
	if ( !text )
	{
		std::cerr << "Failed to render text: " << TTF_GetError() << std::endl;
		return ;
	}
	textTexture = SDL_CreateTextureFromSurface( renderer, text );
	SDL_FreeSurface( text );
	SDL_RenderCopy( renderer, textTexture, NULL, &dest );
	SDL_DestroyTexture( textTexture );
}
