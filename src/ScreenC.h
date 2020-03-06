#include "Game.h"
#include "SDL_ttf.h"



class ScreenC {

public:
	ScreenC(int x, int y, std::string amount);
	~ScreenC();

	void Update();
	void Render();
	void updateNum(std::string s);

private:

	int xpos;
	int ypos;
	std::string amt;
	TTF_Font* font;
	SDL_Color color = { 0, 255, 18 };
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Rect destRec;

	int number;

};