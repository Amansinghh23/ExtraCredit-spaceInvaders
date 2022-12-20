#include "object.h"

object::object()
{
	live = false;
}

object::object(int x, int y)
{
	setX(x);
	setY(y);
}

bool object::isLive()
{
	return live;
}

void object::setLive(bool l)
{
	live = l;
}

