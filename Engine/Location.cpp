#include "Location.h"

void Location::add(const Location & l)
{
	x += l.x;
	y += l.y;
}

bool Location::operator==(const Location & loc) const
{
	if (loc.x == x && loc.y == y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
