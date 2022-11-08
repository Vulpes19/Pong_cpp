#include <SDL.h>
#include <stdio.h>
#include "Window.hpp"
#include <iostream>
#include <limits.h>

int main(int ac, char** av)
{
	Window	window(600, 900);

	window.createWindow();
	return 0;
}