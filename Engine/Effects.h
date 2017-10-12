#pragma once
#include"Colors.h"
#include"Graphics.h"

namespace SpriteEffects
{
	class Chroma
	{
	private:
		Color color;
	public:
		Chroma(Color c)
		{
			color = c;
		}
		void operator()(Color src, int x, int y, Graphics& gfx)
		{
			if (src != color)
			{
				gfx.PutPixel(x, y, src);
			}
		}
	};
	class Substitution
	{
	private: 
		Color color;
		Color chroma;
	public:
		Substitution(Color c,Color ch)
		{
			color = c;
			chroma = ch;
		}
		void operator()(Color src, int x, int y, Graphics& gfx)const
		{
			if (chroma != src)
			{
				gfx.PutPixel(x, y, color);
			}
		}
	};
	class Copy
	{
	public:
		void operator()(Color src, int x, int y, Graphics& gfx)const
		{
			gfx.PutPixel(x, y, src);
		}
	};
	class Ghost
	{
	private:
		Color chroma;
	public:
		Ghost(Color c)
		{
			chroma = c;
		}
		void operator()(Color src, int x, int y, Graphics& gfx)const
		{
			if (src != chroma)
			{
				const Color dstP = gfx.GetPixel(x, y);
				const Color blendP = {
					unsigned char((src.GetR() + dstP.GetR()) / 2),
					unsigned char((src.GetG() + dstP.GetG()) / 2),
					unsigned char((src.GetB() + dstP.GetB()) / 2),
				};
				gfx.PutPixel(x, y, blendP);
			}
		}
	};
}