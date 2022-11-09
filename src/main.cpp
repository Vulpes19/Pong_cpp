#include <SDL.h>
#include <stdio.h>
#include "Window.hpp"
#include <iostream>
#include <limits.h>

int main( int ac, char **av )
{
	(void)av;
	(void)ac;
	Window	window(1240, 900);

	if ( window.createWindow() == EXIT_SUCCESS )
		window.gameLoop();
	return 0;
}