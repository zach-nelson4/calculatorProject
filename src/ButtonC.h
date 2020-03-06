#include "Game.h"
#include "Mouse.h"

class ButtonC{

public:
	ButtonC(const char* texturesheet, const char* texturepressed, int x, int y);
	~ButtonC();

	void Update();
	void Render();
	void checkSelected(Mouse* mouse);
	bool selected;

private:

	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	const char* objPressed;
	const char* objNormal;
	SDL_Rect srcRec, destRec;

};