#include <SDL.h>

#include <cstdio>

#include "cpu/gb_registers.hpp"

int main(int argc, char* argv[])
{
	SDL_Window* window;
	SDL_Surface* surface;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Failed to init SDL %s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
		if (window == NULL)
			printf("Failed to initialize SDL window: %s\n", SDL_GetError());
		else
		{
			surface = SDL_GetWindowSurface(window);
			SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));

			SDL_UpdateWindowSurface(window);

			SDL_Delay(2000);

			SDL_DestroyWindow(window);

			SDL_Quit();
		}
	}

	return 0;
}