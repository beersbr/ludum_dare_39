#pragma once

#include <SDL2/sdl.h>

#include <iostream>

class SDLGame 
{
public:
	SDLGame();
	~SDLGame();
	void init(const char * const name, int width, int height);
	void updateAndRender();

	const bool is_running();
	
private:
	SDL_Window *window;
	int window_width, window_height;

	bool running;

};