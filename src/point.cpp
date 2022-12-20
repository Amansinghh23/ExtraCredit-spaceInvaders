#include "point.h"

point::point()
{
	posX = 0;
	posY = 0;
}

point::point(int x, int y)
{
	posX = x;
	posY = y;
}

void point::moveLeft()
{
	posX--;
}

void point::moveRight()
{
	posX++;
}

void point::moveUp()
{
	posY--;
}

void point::moveDown()
{
	posY++;
}

int point::getX()
{
	return posX;
}

int point::getY()
{
	return posY;
}

void point::setX(int x)
{
	posX = x;
}

void point::setY(int y)
{
	posY = y;
}
