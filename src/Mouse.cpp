#include "Mouse.h"

Mouse::Mouse()
{
	cursor = { 0,0,50,50 };
	tip = { 0,0,1,1 };

}

Mouse::~Mouse()
{

}

void Mouse::draw() 
{
	tip.x = cursor.x;
	tip.y = cursor.y;
}