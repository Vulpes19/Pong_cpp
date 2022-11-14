#include "Window.hpp"

Window::Window( unsigned int w, unsigned int h): width(w), height(h)
{
	window = nullptr;
	renderer = nullptr;
	running = true;
	play = true;
}

Window::~Window( void )
{
	std::cout << "Window is destroyed" << std::endl;
	SDL_DestroyWindow( window );
	SDL_DestroyRenderer( renderer );
	SDL_Quit();
}

int    Window::createWindow( void )
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Error: SDL failed to initialize: "<< SDL_GetError() << '\n';
		return (EXIT_FAILURE);
	}
	window = SDL_CreateWindow("PONG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
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
	SDL_Surface	*icon = IMG_Load("/Users/asus/Documents/Pong_cpp/assets/pong icon.png");
	SDL_SetWindowIcon( window, icon);
	SDL_FreeSurface( icon );
	return (EXIT_SUCCESS);
}

void	Window::handleEvents( void )
{
	while (SDL_PollEvent(&event))
	{
		if ( event.type == SDL_QUIT )
			running = false;
		else if ( event.type == SDL_KEYDOWN)
		{
			switch(event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
				{
					play = true;
					running = true;
					return ;
				}
				default:
					break;
			}
		}
		const	Uint8	*state = SDL_GetKeyboardState( NULL );
		if ( state[SDL_SCANCODE_UP] )
			player.setPosY( player.getPosY() - player.getSpeed() );
		if ( state[SDL_SCANCODE_DOWN])
			player.setPosY( player.getPosY() + player.getSpeed() );
	}
}

void    Window::gameLoop( void )
{
	 while ( running )
	 {
		while ( play )
		{
			menu.renderMenu( renderer );
			menu.mouseEvents( running, play);
		}
		if ( !running || (!running && !play) )
			break ;
		handleEvents();
		if ( !running )
			break ;
		if ( play == true )
			continue ;
		render();
		ball.updateBall( player, enemy, score );
		enemy.updateAI( ball );
	}
}

void	Window::render( void )
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	player.drawRacket( renderer );
	enemy.drawRacket( renderer );
	score.displayScore( renderer );
	ball.drawBall( renderer );
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
	SDL_RenderPresent(renderer);
}
