#include "ButtonC.h"
#include "TextureManager.h"

ButtonC::ButtonC(const char* texturesheet, const char* texturepressed, int x, int y)
{

	objTexture = TextureManager::LoadTexture(texturesheet);
	objPressed = texturepressed;
	objNormal = texturesheet;

	xpos = x;
	ypos = y;
}

ButtonC::~ButtonC() {

}

void ButtonC::Update()
{

	//xpos++;
	//ypos++;

	srcRec.h = 32;
	srcRec.w = 32;
	srcRec.x = 0;
	srcRec.y = 0;

	destRec.x = xpos;
	destRec.y = ypos;
	destRec.w = srcRec.w * 2;
	destRec.h = srcRec.h * 2;

}

void ButtonC::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRec, &destRec);
}

void ButtonC::checkSelected(Mouse* mouse)
{
	if (SDL_HasIntersection(&(mouse->tip), &destRec)) {
		selected = true;

		objTexture = TextureManager::LoadTexture(objPressed);
	}
	else {
		selected = false;
		objTexture = TextureManager::LoadTexture(objNormal);
	}

}