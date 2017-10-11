#pragma once
#include<cmath>

class Vec2
{
public:
	float x;
	float y;
public:
	Vec2();
	Vec2(float x1, float y1);
	Vec2 operator+ (const Vec2 &v)const;
	Vec2 operator- (const Vec2 &v)const;
	Vec2& operator+=(const Vec2 &v);
	Vec2& operator-=(const Vec2 &v);
	Vec2 operator* (const int p)const;
	Vec2 operator/ (const int p)const;
	float GetLength();
};