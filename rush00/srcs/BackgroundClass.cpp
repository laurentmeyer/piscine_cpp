#include "BackgroundClass.hpp"
#include "DisplayManagerClass.hpp"
#include "TimeClass.hpp"
#include <iostream>


size_t		*Background::_height;
float			Background::_lastMove = Time::sinceStart();
float const		Background::_secondsPerMove = 1. / 42;

void			Background::init(void)
{
	static size_t	cols = DisplayManager::getCols();
	static size_t	rows = DisplayManager::getRows();
	bool			up = (bool)(std::rand() % 2);
	bool			r;

	Background::_height = new size_t[cols + 1];
	Background::_height[0] = std::rand() % rows;
	for (size_t i = 1; i < cols + 1; i++)
	{
		r = (std::rand() % 4 == 0);
		if (r)
			up = !up;
		if (Background::_height[i - 1] == 0)
			up = true;
		else if (Background::_height[i - 1] == rows -1)
			up = false;
		Background::_height[i] = Background::_height[i - 1] + (up ? 1 : -1);
	}
}

void			Background::update(void)
{
	static size_t cols = DisplayManager::getCols();
	static size_t rows = DisplayManager::getRows();
	static bool up = (bool)(std::rand() % 2);
	bool r;
	float now = Time::sinceStart();
	float timeDiff = now - Background::_lastMove;

	if (timeDiff < Background::_secondsPerMove)
		return;
	Background::_lastMove = now;
	for (size_t i = 0; i < cols; i++)
		Background::_height[i] = Background::_height[i + 1];
	r = (std::rand() % 4 == 0);
	if (r)
		up = !up;
	if (Background::_height[cols - 1] == 0)
		up = true;
	else if (Background::_height[cols - 1] == rows - 1)
		up = false;
	Background::_height[cols] = Background::_height[cols - 1] + (up ? 1 : -1);
}

void Background::display(void)
{
	static size_t cols = DisplayManager::getCols();
	int y = Background::_height[0];
	size_t prev;
	size_t current;
	size_t next;

	for (size_t x = 0; x < cols; x++)
	{
		prev = Background::_height[x - 1];
		current = Background::_height[x];
		next = Background::_height[x + 1];
		if (next > current && current > prev)
			DisplayManager::pixelPut(x, y = Background::_height[x], '\\' | COLOR_PAIR(1) | A_DIM);
		else if (next > current && current < prev)
			DisplayManager::pixelPut(x, y = Background::_height[x], '.' | COLOR_PAIR(1) | A_DIM);
		else if (next < current && current < prev)
			DisplayManager::pixelPut(x, y = Background::_height[x], '/' | COLOR_PAIR(1) | A_DIM);
		else
			DisplayManager::pixelPut(x, y = Background::_height[x], 'V' | COLOR_PAIR(1) | A_DIM);
	}
}
