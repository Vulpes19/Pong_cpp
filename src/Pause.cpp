#include "Pause.hpp"

Pause::Pause( void )
{
    hover = false;
	color = {0, 255, 255, 255};
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

Pause::~Pause( void )
{
    TTF_CloseFont( font );
	TTF_Quit();
}

void    Pause::writeText( SDL_Renderer *renderer, const char *toDisplay )
{
	SDL_Surface	*text = nullptr;
    textTexture = nullptr;

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

void    Pause::pauseEvents( bool &running, bool &pause )
{
    SDL_Event		event;

    while (SDL_PollEvent(&event))
	{
		if ( event.type == SDL_QUIT )
        {
			running = false;
            pause = false;
        }
        if ( event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN)
        {
            int x, y;
            SDL_GetMouseState( &x, &y );
            if ( x < 670 && x > 570 && y > 550 && y < 600 )
            {
                hover = true;
                if ( event.type == SDL_MOUSEBUTTONDOWN )
                {
                    running = true;
                    pause = false;
                }
            }
            else
                hover = false;
        }
    }
		
}

void    Pause::renderMenu( SDL_Renderer *renderer )
{
    SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	color = {0, 255, 255, 255};
    dest = { 300, 200, 600, 150};
    writeText(renderer, "Ayman's PONG");
    if ( hover )
        color = {255, 255, 255, 255};
    else
	    color = {0, 255, 255, 255};
	dest = { 570, 550, 100, 50 };
    writeText(renderer, "RESUME");
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
	SDL_RenderPresent(renderer);
}