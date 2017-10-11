#include "Surface.h"
#include<cassert>

Surface::Surface(int w, int h)
	:
	width(w),
	height(h),
	pPixels(new Color[width*height])

{
}

Surface::Surface(const Surface & s)
	:
	Surface(s.width,s.height)
{
	const int nPixels = width*height;
	for (int i = 0; i < nPixels; i++)
	{
		pPixels[i] = s.pPixels[i];
	}

}

Surface::Surface(const std::string & filename)
{
	std::ifstream file(filename,std::ios::binary);
	assert(file);

	BITMAPFILEHEADER bmFileHeader;

	file.read(reinterpret_cast<char*>(&bmFileHeader), sizeof(bmFileHeader));

	BITMAPINFOHEADER bmInfoHeader;

	file.read(reinterpret_cast<char*>(&bmInfoHeader), sizeof(bmInfoHeader));

	assert(bmInfoHeader.biBitCount == 24 || bmInfoHeader.biBitCount == 32);
	assert(bmInfoHeader.biCompression == BI_RGB);

	bool is32 = bmInfoHeader.biBitCount == 32;

	width = bmInfoHeader.biWidth;

	int yStart, yEnd, yd;

	if (bmInfoHeader.biHeight < 0)
	{
		height = -bmInfoHeader.biHeight;

		yStart = 0;
		yEnd = height;
		yd = 1;
	}
	else
	{
		height = bmInfoHeader.biHeight;

		yStart = height - 1;
		yEnd = -1;
		yd = -1;
	}

	pPixels = new Color[width*height];

	file.seekg(bmFileHeader.bfOffBits);

	//padding i sonly for 24 bit mode
	const int padding = (4 - (width * 3) % 4) % 4;

	for (int y = yStart; y != yEnd; y+=yd)
	{
		for (int x = 0; x < width; x++)
		{
			PutPixel(x, y, Color (file.get(),file.get(),file.get() ));
			if (is32)
			{
				file.seekg(1, std::ios::cur);
			}
		}
		if (!is32)
		{
			file.seekg(padding, std::ios::cur);
		}
	}
}

Surface & Surface::operator=(const Surface & s)
{
	width = s.width;
	height = s.height;
	delete[] pPixels;
	pPixels = nullptr;
	pPixels = new Color[width*height];
	for (int i = 0; i < width*height; i++)
	{
		pPixels[i] = s.pPixels[i];
	}
	return *this;
}

void Surface::PutPixel(int x, int y, Color c)
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);
	pPixels[y*width + x] = c;
}

Color Surface::GetPixel(int x, int y) const
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);
	return pPixels[y*width + x];
}

int Surface::GetWidth() const
{
	return width;
}

int Surface::GetHeight() const
{
	return height;
}

RectI Surface::GetRect() const
{
	return{ {0,0},{width,height} };
}

Surface::~Surface()
{
	delete[] pPixels;
	pPixels = nullptr;
}
