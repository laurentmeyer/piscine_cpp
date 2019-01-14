
#include "GameManagerClass.hpp"
#include "BackgroundClass.hpp"
#include <iostream>

GameManager::Status		GameManager::status = GameManager::Play;
int const				GameManager::_maxLives = 5;
int						GameManager::_lives = GameManager::_maxLives;
int						GameManager::_score = 0;

GameManager::GameManager(void)
{
	return;
}

GameManager::GameManager(GameManager const & src) 
{
	*this = src;
	return;
}

GameManager::~GameManager(void)
{
	return;
}

GameManager &	GameManager::operator=(GameManager const & rhs)
{
	std::cout << rhs << " has been copied" << std::endl;
	return *this;
}

std::string const GameManager::toString(void) const
{
	return "GameManager";
}

std::ostream &	operator<< (std::ostream & o, GameManager const & rhs)
{
	o << rhs.toString();
	return o;
}

void			GameManager::init(void)
{
	std::srand(std::time(nullptr));
	DisplayManager::init();
	Background::init();
	GameObjectManager::init();
}

void			GameManager::loseOneLife(void)
{
	GameManager::_lives--;
	if (GameManager::_lives <= 0)
		GameObjectManager::deleteGameObject(GameObjectManager::getPlayer());

}

int GameManager::getLives(void)
{
	return GameManager::_lives;
}

int GameManager::getScore(void)
{
	return GameManager::_score;
}

void			GameManager::increaseScore(int points)
{
	GameManager::_score += points;
}

void			GameManager::display(void)
{
	DisplayManager::clear();
	Background::display();
	GameObjectManager::display();
	DisplayManager::update();
}

void			GameManager::update(void)
{
	Time::update();
	InputManager::update();
	Background::update();
	GameObjectManager::update();
}

void			GameManager::quit(std::string message)
{
	DisplayManager::setQuitMsg(message);
	GameManager::status = GameManager::Stop;
}

void			GameManager::destroy(void)
{
	DisplayManager::destroy();
	GameObjectManager::destroy();
}