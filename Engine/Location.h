#pragma once
struct Location
{
	int x;
	int y;
	void add(const Location& l);
	bool operator==(const Location& loc)const;
};