#include "Character.h"

Character::Character(const Vec2 & p, float s)
	:
	sprite("link90x90.bmp"),
	pos(p),
	speed(s),
	vel({0.0,0.0}),
	iCurState(State::StandDown)
{
	for (int i = 0; i < (int)State::StandLeft; i++)
	{
		animations.emplace_back(Animation(90, 90 * i, 90, 90, 4, sprite, 0.1));
	}
	for (int i = (int)State::StandLeft; i < (int)State::Count; i++)
	{
		animations.emplace_back(Animation(0, 90 * (i - (int)State::StandLeft), 90, 90, 1, sprite, 0.1));
	}
}

void Character::Draw(Graphics & gfx)
{
	animations[(int)iCurState].Draw({ (int)pos.x,(int)pos.y }, gfx);
}

void Character::Update(float dt)
{	
	Vec2 v = vel*dt;
	pos += vel*dt;
	animations[(int)iCurState].Update(dt);
}

void Character::SetDirection(const Vec2 & dir)
{

	if (dir.x < 0)
	{
		iCurState = State::WalkingLeft;
	}
	else if (dir.x > 0)
	{
		iCurState = State::WalkingRight;
	}
	else if (dir.y > 0)
	{
		iCurState = State::WalkingDown;
	}
	else if (dir.y < 0)
	{
		iCurState = State::WalkingUp;
	}
	else
	{
		if (vel.x < 0)
		{
			iCurState = State::StandLeft;
		}
		else if (vel.x > 0)
		{
			iCurState = State::StandRight;
		}
		else if (vel.y > 0)
		{
			iCurState = State::StandDown;
		}
		else if (vel.y < 0)
		{
			iCurState = State::StandUp;
		}
	}
	vel = dir*speed;
}
