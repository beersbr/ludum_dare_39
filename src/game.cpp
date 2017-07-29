#include "game.h"


SDLGame::SDLGame()
{
	window        = nullptr;
	window_width  = -1;
	window_height = -1;
}


void SDLGame::init(const char * const name, int width, int height)
{

	if ( SDL_Init(SDL_INIT_EVERYTHING) != 0 ) {
		std::cout << "Could not start sdl2" << std::endl;
		return;
	}

	window_width = width;
	window_height = height;

	int flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI;
	// int flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;

	window = SDL_CreateWindow(name,
	                          SDL_WINDOWPOS_CENTERED,
	                          SDL_WINDOWPOS_CENTERED,
	                          window_width,
	                          window_height,
	                          flags);

	running = true;
}


void SDLGame::updateAndRender()
{
	SDL_Event event;
	while ( SDL_PollEvent(&event) ) {
		switch ( event.type ) {
			case SDL_QUIT: 
				running = false;
		}
	}
}


SDLGame::~SDLGame()
{
	SDL_DestroyWindow(window);
}


const bool SDLGame::is_running()
{
	return this->running;
}