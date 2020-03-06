
#ifndef Game_h
#define Game_h
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>


class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; };
	
	static SDL_Renderer* renderer;
private:
	bool isRunning;
	SDL_Window *window;
	int cnt;
};


#endif
