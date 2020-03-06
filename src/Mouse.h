#include "Game.h"

#ifndef Mouse_H
#define Mouse_H

class Mouse{
public:
	SDL_Rect cursor, tip;

	Mouse();
	~Mouse();
	void draw();
};

#endif

