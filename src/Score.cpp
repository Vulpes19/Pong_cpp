#include "Score.hpp"
#include <string.h>

Score::Score( void )
{
	playerScore = 0;
	enemyScore = 0;
	text = NULL;
	textTexture = NULL;
	color = {10, 0, 0, 0};
	if ( TTF_Init() < 0 )
	{
		std::cerr << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
		return ;
	}
	font = TTF_OpenFont("font.ttf", 24);
	if ( !font )
	{
		std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
		return ;    
	}
}

Score::~Score( void )
{
	std::cout << "Score is destroyed" << std::endl;
	TTF_CloseFont( font );
	TTF_Quit();
}

void	Score::displayScore( SDL_Renderer *renderer )
{
	char *str1 = ft_itoa(playerScore);
	char *str2 = ft_itoa(enemyScore);
	const char	*toDisplay = strcat( str1, str2 );

	free(str1);
	free(str2);
	text = TTF_RenderText_Solid( font, toDisplay, color );
	if ( !text )
	{
		std::cerr << "Failed to render text: " << TTF_GetError() << std::endl;
		return ;
	}
	textTexture = SDL_CreateTextureFromSurface( renderer, text );
	SDL_Rect dest = { 0, 0, text->w, text->h };
	SDL_RenderCopy( renderer, textTexture, &dest, NULL );
}
