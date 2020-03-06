#include "ScreenC.h"
#include "TextureManager.h"


ScreenC::ScreenC(int x, int y, std::string amount)
{

	
	xpos = x;
	ypos = y;
	amt = amount;
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	font = TTF_OpenFont("assets/digital-7.ttf", 35);

}

ScreenC::~ScreenC() {
	TTF_CloseFont(font);
}

void ScreenC::Update()
{
	surface = TTF_RenderText_Solid(font, amt.c_str(), color);
	texture = SDL_CreateTextureFromSurface(Game::renderer, surface);

	int texW = 0;
	int texH = 0;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

	destRec.x = xpos;
	destRec.y = ypos;
	destRec.w = texW * 2;
	destRec.h = texH * 2;

}

void ScreenC::Render()
{
	
	SDL_RenderCopy(Game::renderer, texture, NULL, &destRec);
	SDL_RenderPresent(Game::renderer);
}

void ScreenC::updateNum(std::string s) {
	amt = s;

}