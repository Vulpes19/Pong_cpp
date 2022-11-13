#include "Menu.hpp"

Menu::Menu( void )
{
	color = {0, 255, 255, 255};
    hover_play = false;
    hover_exit = false;
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

Menu::~Menu( void )
{
    std::cout << "Menu is destroyed" << std::endl;
	TTF_CloseFont( font );
	TTF_Quit();
}

void    Menu::writeText( SDL_Renderer *renderer, const char *toDisplay )
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

void    Menu::mouseEvents( bool &running, bool &menu )
{
    SDL_Event		event;

    while (SDL_PollEvent(&event))
	{
		if ( event.type == SDL_QUIT )
        {
			running = false;
            menu = false;
        }
        if ( event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN)
        {
            int x, y;
            SDL_GetMouseState( &x, &y );
            if ( x < 670 && x > 570 && y > 550 && y < 600 )
            {
                hover_play = true;
                if ( event.type == SDL_MOUSEBUTTONDOWN )
                {
                    running = true;
                    menu = false;
                }
            }
            else
                hover_play = false;
            if ( x < 670 && x > 570 && y > 650 && y < 700 )
            { 
                hover_exit = true;
                if ( event.type == SDL_MOUSEBUTTONDOWN )
                {
                    running = false;
                    menu = false;
                }
            }
            else
                hover_exit = false;
        }
    }
		
}

void    Menu::renderMenu( SDL_Renderer *renderer )
{
    SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	color = {0, 255, 255, 255};
    dest = { 300, 200, 600, 150};
    writeText(renderer, "Ayman's PONG");
    if ( hover_play )
        color = {255, 255, 255, 255};
    else
	    color = {0, 255, 255, 255};
	dest = { 570, 550, 100, 50 };
    writeText(renderer, "PLAY");
     if ( hover_exit )
        color = {255, 255, 255, 255};
    else
	    color = {0, 255, 255, 255};
	dest = { 570, 650, 100, 50 };
    writeText(renderer, "EXIT");
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
	SDL_RenderPresent(renderer);
}