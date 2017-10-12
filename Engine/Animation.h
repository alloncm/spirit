#pragma once
#include"Colors.h"
#include"Graphics.h"
#include<vector>
#include"Rect.h"
#include"Surface.h"
#include"Vec2.h"


class Animation
{
public:
	Animation(int x, int y, int width, int height, int count, const Surface& s,float ht, Color chroma = Colors::Magenta);
	void Update(float dt);
	void Draw(const Location& l, Graphics& gfx);
	void Draw(const Location& l, Graphics& gfx, RectI& clip);
private:
	void Advance();
private:
	Color chroma;
	const Surface& sprite;
	std::vector<RectI> frames;
	int iCurFrame = 0;
	float holdTime;
	float curFrameTime = 0.0f;
};