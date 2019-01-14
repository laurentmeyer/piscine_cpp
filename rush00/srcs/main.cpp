#include <ctime>
#include "GameManagerClass.hpp"
# include <curses.h>

int main(void)
{
	float lastRender = 0;
	float timeDiff;
	float const secondsPerFrame = 1. / 60;

	GameManager::init();
	while (GameManager::Stop != GameManager::status)
	{
		while ((timeDiff = Time::sinceStart() - lastRender) < secondsPerFrame)
			GameManager::update();
		lastRender = Time::sinceStart();
		GameManager::display();
	}
	GameManager::destroy();
	std::cout << DisplayManager::getQuitMsg() << std::endl;
}