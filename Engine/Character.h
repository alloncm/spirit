#pragma once
#include"Animation.h"
#include"vector"
#include"Vec2.h"
#include"Graphics.h"

class Character
{
public:
	Character(const Vec2& pos, float speed,int w,int h);
	void Draw( Graphics& gfx);
	void Update(float dt);
	void SetDirection(const Vec2& dir);
	RectI GetCharacterRect()const;
private:
	enum class State
	{
		WalkingLeft,
		WalkingRight,
		WalkingUp,
		WalkingDown,
		StandLeft,
		StandRight,
		StandUp,
		StandDown,
		Count
	};
private:
	Surface sprite;
	std::vector<Animation> animations;
	State iCurState;
	Vec2 pos;
	Vec2 vel;
	float speed;
	int width;
	int height;
};