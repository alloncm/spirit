#include "Font.h"
#include<assert.h>

Font::Font(std::string filename, Color chroma)
	:
	sprite(filename),
	gliphWidth(sprite.GetWidth()/nColomns),
	gliphHeight(sprite.GetHeight()/nRows),
	chroma(chroma)
{
	//some assertions
	assert(gliphWidth*nColomns == sprite.GetWidth());
	assert(gliphHeight*nRows == sprite.GetHeight());
}

void Font::DrawText(std::string & src, Location & pos, Graphics & gfx)
{
	auto newpos = pos;
	for (auto c : src)
	{
		if (c == '\n')
		{
			newpos.x = pos.x;
			newpos.y += gliphHeight;
			continue;
		}
		gfx.DrawSpriteSubstitute(newpos.x, newpos.y,Colors::White, MapGleaphRect(c), sprite,chroma);
		newpos.x += gliphWidth;
	}
}

RectI Font::MapGleaphRect(char c)
{
	char mander = c - ' ';
	int y = 0;
	while(mander >= nColomns)
	{
		mander -= nColomns;
		y++;
	}
	RectI r((int)mander*gliphWidth, y*gliphHeight, gliphWidth, gliphHeight);
	return r;
}
