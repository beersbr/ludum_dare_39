#include <SDL2/sdl.h>

#include "game.h"

const char * const WINDOW_NAME = "SDL Ludum Dare 39";
const int WINDOW_WIDTH         = 800;
const int WINDOW_HEIGHT        = 600;

int main( int argc, char *argv[] )
{
	SDLGame *game = new SDLGame();
	game->init(WINDOW_NAME,
	           WINDOW_WIDTH,
	           WINDOW_HEIGHT);

	while ( game->is_running() ) {
		game->updateAndRender();
	}

	return 0;
}