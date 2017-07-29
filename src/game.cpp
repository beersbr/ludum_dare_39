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

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	window = SDL_CreateWindow(name,
	                          SDL_WINDOWPOS_CENTERED,
	                          SDL_WINDOWPOS_CENTERED,
	                          window_width,
	                          window_height,
	                          flags);

	SDL_GLContext main_context = SDL_GL_CreateContext(window);


	#ifdef _WIN32
	glewExperimental = GL_TRUE;
	glewInit();
	#endif

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);

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

	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SDL_GL_SwapWindow(window);
}


SDLGame::~SDLGame()
{
	SDL_DestroyWindow(window);
}


const bool SDLGame::is_running()
{
	return this->running;
}