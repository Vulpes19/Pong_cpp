#include "Window.hpp"

Window::Window( unsigned int w, unsigned int h): width(w), height(h)
{
	window = NULL;
	renderer = NULL;
	running = false;
}

Window::~Window( void )
{
	std::cout << "Window is destroyed" << std::endl;
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int    Window::createWindow( void )
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Error: SDL failed to initialize: "<< SDL_GetError() << '\n';
		return (EXIT_FAILURE);
	}
	window = SDL_CreateWindow("TETRIS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	if(!window)
	{
		std::cerr << "Error: Failed to open window: "<< SDL_GetError() << '\n';
		return (EXIT_FAILURE);
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(!renderer)
	{
		std::cerr << "Error: Failed to create renderer: "<< SDL_GetError() << '\n';
		return (EXIT_FAILURE);
	}
	running = true;
	gameLoop();
	return (EXIT_SUCCESS);
}

void	Window::handleEvents( void )
{
	while (SDL_PollEvent(&event))
	{
		if ( event.type == SDL_QUIT )
			running = false;
		else if ( event.type == SDL_KEYDOWN )
		{
			switch(event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
					running = false;
					break;
				case SDLK_UP:
					player.setPosY( player.getPosY() - player.getSpeed() );
					break ;
				case SDLK_DOWN:
					player.setPosY( player.getPosY() + player.getSpeed() );
					break ;
				default:
					break;
			}
		}
	}
}

void    Window::gameLoop( void )
{
	 while (running)
	 {
		handleEvents();
		render();
	}
}

void	Window::render( void )
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
	player.drawRacket( renderer );
	enemy.drawRacket( renderer );
	score.displayScore( renderer );
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderPresent(renderer);
}
