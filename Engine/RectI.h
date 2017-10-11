#pragma once

#include"Location.h"

class RectI
{
private:
	Location tLeft;
	Location bRight;

public:
	RectI(int x, int y, int width, int height);
	RectI(Location tLeft, Location bRight);
	RectI();
	RectI(RectI& r);
	RectI(int width, int height, Location center);
	RectI& operator=(RectI& r);
	int GetWidth()const;
	int GetHeight()const;
	const Location& GetTopLeft()const;
	const Location& GetBotoomRight()const;
	bool IsInside(const Location& l)const;
};
