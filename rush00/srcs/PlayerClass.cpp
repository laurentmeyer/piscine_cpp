#include "PlayerClass.hpp"
#include "ProjectileClass.hpp"
#include "InputManagerClass.hpp"
#include "GameManagerClass.hpp"
#include <iostream>
#include <unistd.h>

Player::Player(void) : _name("one")
{
	this->_curse = ACS_RARROW | A_ALTCHARSET | A_REVERSE;
	return;
}

Player::Player(int x, int y) : _name("one")
{
	this->setX(x);
	this->setY(y);
	this->_curse = ACS_RARROW | A_ALTCHARSET | A_REVERSE;
	return;
}

Player::~Player(void)
{
	return;
}

std::string const Player::toString(void) const
{
	return "Player " + this->getName();
}

std::ostream &operator<<(std::ostream &o, Player const &rhs)
{
	o << rhs.toString();
	return o;
}

std::string Player::getName(void) const { return (this->_name); }
void Player::setName(std::string name) { this->_name = name; }
void Player::updatePosition(AGameObject *map[])
{
	static bool playSound = ( access( "./assets/shoot.mp3", F_OK ) != -1 );
	int newX = this->getX();
	int newY = this->getY();
	static int row = DisplayManager::getRows();
	static int col = DisplayManager::getCols();
	AGameObject	*target;

	if (InputManager::getKeyStatus('w'))
	{
		if (newY > 0)
			newY--;
	}
	if (InputManager::getKeyStatus('s'))
	{
		if (newY < row - 1)
			newY++;
	}
	if (InputManager::getKeyStatus('a'))
	{
		if (newX > 0)
			newX--;
	}
	if (InputManager::getKeyStatus('d'))
	{
		if (newX < col - 1)
			newX++;
	}
	if (InputManager::getKeyStatus(' '))
	{
		if (playSound)
			system("afplay ./assets/shoot.mp3 -v 0.6&");
		GameObjectManager::addGameObject(new Projectile(newX + 1, newY, Projectile::Right, 200, this));
	}
	if (nullptr != (target = map[newY * col + newX]))
	{
		target->collide(this);
		this->collide(target);
	}
	map[newY * col + newX] = this;
	this->setX(newX);
	this->setY(newY);
}

void	Player::collide(AGameObject *target)
{
	(void)target;
	GameManager::loseOneLife();
}

void	Player::collide(AGameObject *target, AGameObject const *shooter)
{
	(void)shooter;
	(void)target;
	GameManager::loseOneLife();
}