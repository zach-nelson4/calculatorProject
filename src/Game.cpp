////////////////////////////////////////////////////////////////////////////////////////////////
//
// Name: Calculator.exe
// Author: Zachary Nelson
// Date: March 4th 2020
// This program is a simple 2 digit calculator created using SDL
// It can add, multiply, subtract, and divide two digit numbers. 
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ButtonC.h"
#include "Mouse.h"
#include "SDL_ttf.h"
#include "ScreenC.h"
#include <string.h>
#include <sstream>

//Declaring all objects needed
GameObject* base;

ButtonC* B1;
ButtonC* B2;
ButtonC* B3;
ButtonC* B4;
ButtonC* B5;
ButtonC* B6;
ButtonC* B7;
ButtonC* B8;
ButtonC* B9;
ButtonC* B0;
ButtonC* BP;
ButtonC* BM;
ButtonC* BX;
ButtonC* BD;
ButtonC* BE;
ButtonC* BC;
ScreenC* NUMONE;
ScreenC* NUMTWO;
ScreenC* OP;


bool firstPart = true;
std::string numOne;
std::string numTwo;
std::string op;

Mouse* mouse;
SDL_Renderer* Game::renderer = nullptr;
int scale = 2;

Game::Game()
{
	static Mouse* m = new Mouse;
	mouse = m;
}
Game::~Game()
{}

//Init function, this creates the window and the game
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) 
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		TTF_Init();
		isRunning = true;

	}

	//Load player
	base = new GameObject("assets/calcBase.png", 0, 0);
	B1= new ButtonC("assets/1B.png", "assets/1P.png", 0, 32*scale);
	B2 = new ButtonC("assets/2B.png", "assets/2P.png", 32*scale , 32 * scale);
	B3 = new ButtonC("assets/3B.png", "assets/3P.png", 64 * scale, 32 * scale);
	BP = new ButtonC("assets/plusB.png", "assets/plusP.png", 96 * scale, 32 * scale);

	B4 = new ButtonC("assets/4B.png", "assets/4P.png", 0, 32 * scale*2);
	B5 = new ButtonC("assets/5B.png", "assets/5P.png", 32 * scale, 32 * scale*2);
	B6 = new ButtonC("assets/6B.png", "assets/6P.png", 64 * scale, 32 * scale*2);
	BM = new ButtonC("assets/minusB.png", "assets/minusP.png", 96 * scale, 32 * scale*2);

	B7 = new ButtonC("assets/7B.png", "assets/7P.png", 0, 32 * scale * 3);
	B8 = new ButtonC("assets/8B.png", "assets/8P.png", 32 * scale, 32 * scale * 3);
	B9 = new ButtonC("assets/9B.png", "assets/9P.png", 64 * scale, 32 * scale * 3);
	BX = new ButtonC("assets/multiB.png", "assets/multiP.png", 96 * scale, 32 * scale * 3);

	B0 = new ButtonC("assets/0B.png", "assets/0P.png", 32 * scale, 32 * scale * 4);
	BD = new ButtonC("assets/divB.png", "assets/divP.png", 64 * scale, 32 * scale * 4);
	BE = new ButtonC("assets/equalsB.png", "assets/equalsP.png", 96 * scale, 32 * scale * 4);
	BC = new ButtonC("assets/CB.png", "assets/CP.png", 0, 32 * scale * 4);

	NUMONE = new ScreenC(5, 0, "0");
	NUMTWO = new ScreenC(10 + (32 * 3), 0, " ");
	OP = new ScreenC(10 + (32 * 2), 0, " ");
}

//Creates and deals with the events
void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				if (numOne.size() > 2) {
					numOne = "";
				}
				//Checking which button is selected and adding that to the amount

				//Button 1 selected
				if (B1->selected) {

					//Check to see if on first number
					if (firstPart == true) {

						//Case statements to see number size. If number size is currently 0, then put in 10s digit. If 10s digit holds a number, put into 1s digit. 
						//If both are full, move the 1s to the 10s and put new number in the 1s.
						switch (numOne.size()) {
						case 0:
							numOne = numOne + '1';
							break;
						case 1:
							numOne = numOne + '1';
							break;
						case 2:
							numOne[0] = numOne[1];
							numOne[1] = '1';
							break;
						default:
							numOne[0] = '0';
							numOne[1] = '1';
							break;
						}
					}

					//Otherwise, if we're on number two, do the same thing with numTwo
					else {
						switch (numTwo.size()) {
						case 0:
							numTwo = numTwo + '1';
							break;
						case 1:
							numTwo = numTwo + '1';
							break;
						case 2:
							numTwo[0] = numTwo[1];
							numTwo[1] = '1';
							break;
						}
					}
					break;
				}

				//Button 2 selected
				if (B2->selected) {

					//Check to see if on first number
					if (firstPart == true) {

						//Case statements to see number size. If number size is currently 0, then put in 10s digit. If 10s digit holds a number, put into 1s digit. 
						//If both are full, move the 1s to the 10s and put new number in the 1s.
						switch (numOne.size()) {
						case 0:
							numOne = numOne + '2';
							break;
						case 1:
							numOne = numOne + '2';
							break;
						case 2:
							numOne[0] = numOne[1];
							numOne[1] = '2';
							break;
						default:
							numOne[0] = '0';
							numOne[1] = '2';
							break;
						}
					}

					//Otherwise, if we're on number two, do the same thing with numTwo
					else {
						switch (numTwo.size()) {
						case 0:
							numTwo = numTwo + '2';
							break;
						case 1:
							numTwo = numTwo + '2';
							break;
						case 2:
							numTwo[0] = numTwo[1];
							numTwo[1] = '2';
							break;
						}
					}
					break;
				}

				//Button 3 selected
				if (B3->selected) {

					//Check to see if on first number
					if (firstPart == true) {

						//Case statements to see number size. If number size is currently 0, then put in 10s digit. If 10s digit holds a number, put into 1s digit. 
						//If both are full, move the 1s to the 10s and put new number in the 1s.
						switch (numOne.size()) {
						case 0:
							numOne = numOne + '3';
							break;
						case 1:
							numOne = numOne + '3';
							break;
						case 2:
							numOne[0] = numOne[1];
							numOne[1] = '3';
							break;
						default:
							numOne[0] = '0';
							numOne[1] = '3';
							break;
						}
					}

					//Otherwise, if we're on number two, do the same thing with numTwo
					else {
						switch (numTwo.size()) {
						case 0:
							numTwo = numTwo + '3';
							break;
						case 1:
							numTwo = numTwo + '3';
							break;
						case 2:
							numTwo[0] = numTwo[1];
							numTwo[1] = '3';
							break;
						}
					}
					break;
				}

				//Button + Selected
				if (BP->selected) {
					if (firstPart == true) {
						firstPart = false;
						if (numOne.size() == 0) {
							numOne = "00";
						}
						if (numOne.size() == 1) {
							numOne = '0' + numOne;
						}
						op = '+';
						OP->updateNum("+");
					}
					break;
				}

				//Button 4 Selected
				if (B4->selected) {

					//Check to see if on first number
					if (firstPart == true) {

						//Case statements to see number size. If number size is currently 0, then put in 10s digit. If 10s digit holds a number, put into 1s digit. 
						//If both are full, move the 1s to the 10s and put new number in the 1s.
						switch (numOne.size()) {
						case 0:
							numOne = numOne + '4';
							break;
						case 1:
							numOne = numOne + '4';
							break;
						case 2:
							numOne[0] = numOne[1];
							numOne[1] = '4';
							break;
						default:
							numOne[0] = '0';
							numOne[1] = '4';
							break;
						}
					}

					//Otherwise, if we're on number two, do the same thing with numTwo
					else {
						switch (numTwo.size()) {
						case 0:
							numTwo = numTwo + '4';
							break;
						case 1:
							numTwo = numTwo + '4';
							break;
						case 2:
							numTwo[0] = numTwo[1];
							numTwo[1] = '4';
							break;
						}
					}
					break;
				}

				//Button 5 Selected
				if (B5->selected) {

					//Check to see if on first number
					if (firstPart == true) {

						//Case statements to see number size. If number size is currently 0, then put in 10s digit. If 10s digit holds a number, put into 1s digit. 
						//If both are full, move the 1s to the 10s and put new number in the 1s.
						switch (numOne.size()) {
						case 0:
							numOne = numOne + '5';
							break;
						case 1:
							numOne = numOne + '5';
							break;
						case 2:
							numOne[0] = numOne[1];
							numOne[1] = '5';
							break;
						default:
							numOne[0] = '0';
							numOne[1] = '5';
							break;
						}
					}

					//Otherwise, if we're on number two, do the same thing with numTwo
					else {
						switch (numTwo.size()) {
						case 0:
							numTwo = numTwo + '5';
							break;
						case 1:
							numTwo = numTwo + '5';
							break;
						case 2:
							numTwo[0] = numTwo[1];
							numTwo[1] = '5';
							break;
						}
					}
					break;
				}

				//Button 6 Selected
				if (B6->selected) {

					//Check to see if on first number
					if (firstPart == true) {

						//Case statements to see number size. If number size is currently 0, then put in 10s digit. If 10s digit holds a number, put into 1s digit. 
						//If both are full, move the 1s to the 10s and put new number in the 1s.
						switch (numOne.size()) {
						case 0:
							numOne = numOne + '6';
							break;
						case 1:
							numOne = numOne + '6';
							break;
						case 2:
							numOne[0] = numOne[1];
							numOne[1] = '6';
							break;
						default:
							numOne[0] = '0';
							numOne[1] = '6';
							break;
						}
					}

					//Otherwise, if we're on number two, do the same thing with numTwo
					else {
						switch (numTwo.size()) {
						case 0:
							numTwo = numTwo + '6';
							break;
						case 1:
							numTwo = numTwo + '6';
							break;
						case 2:
							numTwo[0] = numTwo[1];
							numTwo[1] = '6';
							break;
						}
					}
					break;
				}

				//Minus button selected
				if (BM->selected) {
					if (firstPart == true) {
						firstPart = false;
						if (numOne.size() == 0) {
							numOne = "00";
						}
						if (numOne.size() == 1) {
							numOne = '0' + numOne;
						}
						op = '-';
						OP->updateNum("-");
					}
					break;
				}

				//Button 7 Selected
				if (B7->selected) {

					//Check to see if on first number
					if (firstPart == true) {

						//Case statements to see number size. If number size is currently 0, then put in 10s digit. If 10s digit holds a number, put into 1s digit. 
						//If both are full, move the 1s to the 10s and put new number in the 1s.
						switch (numOne.size()) {
						case 0:
							numOne = numOne + '7';
							break;
						case 1:
							numOne = numOne + '7';
							break;
						case 2:
							numOne[0] = numOne[1];
							numOne[1] = '7';
							break;
						default:
							numOne[0] = '0';
							numOne[1] = '7';
							break;
						}
					}

					//Otherwise, if we're on number two, do the same thing with numTwo
					else {
						switch (numTwo.size()) {
						case 0:
							numTwo = numTwo + '7';
							break;
						case 1:
							numTwo = numTwo + '7';
							break;
						case 2:
							numTwo[0] = numTwo[1];
							numTwo[1] = '7';
							break;
						}
					}
					break;
				}

				//Button 8 selected
				if (B8->selected) {

					//Check to see if on first number
					if (firstPart == true) {

						//Case statements to see number size. If number size is currently 0, then put in 10s digit. If 10s digit holds a number, put into 1s digit. 
						//If both are full, move the 1s to the 10s and put new number in the 1s.
						switch (numOne.size()) {
						case 0:
							numOne = numOne + '8';
							break;
						case 1:
							numOne = numOne + '8';
							break;
						case 2:
							numOne[0] = numOne[1];
							numOne[1] = '8';
							break;
						default:
							numOne[0] = '0';
							numOne[1] = '8';
							break;
						}
					}

					//Otherwise, if we're on number two, do the same thing with numTwo
					else {
						switch (numTwo.size()) {
						case 0:
							numTwo = numTwo + '8';
							break;
						case 1:
							numTwo = numTwo + '8';
							break;
						case 2:
							numTwo[0] = numTwo[1];
							numTwo[1] = '8';
							break;
						}
					}
					break;
				}

				//Button 9 selected
				if (B9->selected) {

					//Check to see if on first number
					if (firstPart == true) {

						//Case statements to see number size. If number size is currently 0, then put in 10s digit. If 10s digit holds a number, put into 1s digit. 
						//If both are full, move the 1s to the 10s and put new number in the 1s.
						switch (numOne.size()) {
						case 0:
							numOne = numOne + '9';
							break;
						case 1:
							numOne = numOne + '9';
							break;
						case 2:
							numOne[0] = numOne[1];
							numOne[1] = '9';
							break;
						default:
							numOne[0] = '0';
							numOne[1] = '9';
							break;
						}
					}

					//Otherwise, if we're on number two, do the same thing with numTwo
					else {
						switch (numTwo.size()) {
						case 0:
							numTwo = numTwo + '9';
							break;
						case 1:
							numTwo = numTwo + '9';
							break;
						case 2:
							numTwo[0] = numTwo[1];
							numTwo[1] = '9';
							break;
						}
					}
					break;
				}

				//Button x selected
				if (BX->selected) {
					if (firstPart == true) {
						firstPart = false;
						if (numOne.size() == 0) {
							numOne = "00";
						}
						if (numOne.size() == 1) {
							numOne = '0' + numOne;
						}
						op = 'x';
						OP->updateNum("x");
					}
					break;
				}

				//Button 0 selected
				if (B0->selected) {

					//Check to see if on first number
					if (firstPart == true) {

						//Case statements to see number size. If number size is currently 0, then put in 10s digit. If 10s digit holds a number, put into 1s digit. 
						//If both are full, move the 1s to the 10s and put new number in the 1s.
						switch (numOne.size()) {
						case 0:
							numOne = numOne + '0';
							break;
						case 1:
							numOne = numOne + '0';
							break;
						case 2:
							numOne[0] = numOne[1];
							numOne[1] = '0';
							break;
						default:
							numOne[0] = '0';
							numOne[1] = '0';
							break;
						}
					}

					//Otherwise, if we're on number two, do the same thing with numTwo
					else {
						switch (numTwo.size()) {
						case 0:
							numTwo = numTwo + '0';
							break;
						case 1:
							numTwo = numTwo + '0';
							break;
						case 2:
							numTwo[0] = numTwo[1];
							numTwo[1] = '0';
							break;
						}
					}
					break;
				}

				// Button / selected
				if (BD->selected) {
					if (firstPart == true) {
						firstPart = false;
						if (numOne.size() == 0) {
							numOne = "00";
						}
						if (numOne.size() == 1) {
							numOne = '0' + numOne;
						}
						op = '/';
						OP->updateNum("/");
					}
					break;
				}

				// Button C selected
				if (BC->selected) {
					numOne = "";
					numTwo = "";
					op = ' ';
					OP->updateNum("");
					firstPart = true;
				}

				//Equals Button Selected
				if (BE->selected) {
					//If on first number, do nothing, otherwise:
					if (firstPart == false) {
						int one, two, total;
						std::istringstream(numOne) >> one;
						std::istringstream(numTwo) >> two;

						switch (op[0]) {
						case '+':
							total = one + two;
							numOne = std::to_string(total);
							break;
						case '-':
							total = one - two;
							numOne = std::to_string(total);
							break;
						case 'x':
							total = one * two;
							numOne = std::to_string(total);
							break;
						case '/':
							if (two != 0) {
								total = one / two;
								numOne = std::to_string(total);
							}
							else {
								numOne = "Error";
							}
						}


						//Resetting everything back to defaults
						numTwo = "";
						op = "";
						OP->updateNum(" ");
						firstPart = true;
					}
					break;
				}
				break;

			default:
				break;
			}
	}

	//Normally, I would put these all in a single array and loop through, however, when I tried, it just didn't work.
	NUMONE->updateNum(numOne);
	NUMTWO->updateNum(numTwo);

	B1->checkSelected(mouse);
	B2->checkSelected(mouse);
	B3->checkSelected(mouse);
	BP->checkSelected(mouse);

	B4->checkSelected(mouse);
	B5->checkSelected(mouse);
	B6->checkSelected(mouse);
	BM->checkSelected(mouse);

	B7->checkSelected(mouse);
	B8->checkSelected(mouse);
	B9->checkSelected(mouse);
	BX->checkSelected(mouse);

	B0->checkSelected(mouse);
	BD->checkSelected(mouse);
	BE->checkSelected(mouse);
	BC->checkSelected(mouse);
}


//Updates the game every loop
void Game::update()
{
	//Future loop
	base->Update();

	B1->Update();
	B2->Update();
	B3->Update();
	BP->Update();

	B4->Update();
	B5->Update();
	B6->Update();
	BM->Update();

	B7->Update();
	B8->Update();
	B9->Update();
	BX->Update();

	B0->Update();
	BD->Update();
	BE->Update();
	BC->Update();

	NUMONE->Update();
	NUMTWO->Update();
	OP->Update();
	SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
}

//Render everything to the screen
void Game::render()
{
	//Future loop
	SDL_RenderClear(renderer);
	mouse->draw();
	base->Render();

	B1->Render();
	B2->Render();
	B3->Render();
	BP->Render();

	B4->Render();
	B5->Render();
	B6->Render();
	BM->Render();

	B7->Render();
	B8->Render();
	B9->Render();
	BX->Render();

	B0->Render();
	BD->Render();
	BE->Render();
	BC->Render();

	NUMONE->Render();
	NUMTWO->Render();
	OP->Render();
	SDL_RenderPresent(renderer);
}

//Clean up everything going on
void Game::clean()
{
	//Again, future loop
	delete mouse;
	delete base;

	delete B1;
	delete B2;
	delete B3;
	delete B4;
	delete B5;
	delete B6;
	delete B7;
	delete B8;
	delete B9;
	delete B0;

	delete BD;
	delete BE;
	delete BC;
	delete BP;
	delete BM;
	delete NUMONE;
	delete NUMTWO;
	delete OP;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_Quit();
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

