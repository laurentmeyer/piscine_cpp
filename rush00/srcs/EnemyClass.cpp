#include "EnemyClass.hpp"
#include "InputManagerClass.hpp"
#include "GameManagerClass.hpp"
#include "GameObjectManagerClass.hpp"
#include "TimeClass.hpp"
#include <iostream>
#include <unistd.h>

int const	Enemy::_pointsValue = 1000;

Enemy::Enemy(int x, int y) : _secondsPerMove(1. / 3), _secondsPerShot(1. / 2)
{
	this->setX(x);
	this->setY(y);
	this->_curse = ACS_CKBOARD;
	this->_lastMoved = Time::sinceStart();
	this->_lastShot = Time::sinceStart();
	return;
}

Enemy::~Enemy(void)
{
	return;
}

std::string const Enemy::toString(void) const
{
	return "Enemy";
}

std::ostream &operator<<(std::ostream &o, Enemy const &rhs)
{
	o << rhs.toString();
	return o;
}

void Enemy::_shoot(void)
{
	float now = Time::sinceStart();
	float timeDiff = now - this->_lastShot;

	if (timeDiff >= this->_secondsPerShot)
	{
		if (0 == std::rand() % 3)
			GameObjectManager::addGameObject(new Projectile(this->getX() - 2, this->getY(), Projectile::Left, 50, this));
		this->_lastShot = now;
	}
}

void Enemy::updatePosition(AGameObject *map[])
{
	int newX = this->getX();
	int newY = this->getY();
	static int row = DisplayManager::getRows();
	static int col = DisplayManager::getCols();
	float now = Time::sinceStart();
	float timeDiff = now - this->_lastMoved;
	AGameObject	*target;

	if (timeDiff >= this->_secondsPerMove)
	{
		newX += -1;
		this->_lastMoved = now;
	}
	if (newY < 0 || newY >= row || newX < 0 || newX >= col)
	{
		GameObjectManager::deleteGameObject(this);
		return ;
	}
	if (nullptr != (target = map[newY * col + newX]))
	{
		target->collide(this);
		this->collide(target);
	}
	map[newY * col + newX] = this;
	this->setX(newX);
	this->setY(newY);
	this->_shoot();
	return ;
}

void	Enemy::collide(AGameObject *target)
{
	(void)target;
	GameObjectManager::deleteGameObject(this);
}

void	Enemy::collide(AGameObject *target, AGameObject const *shooter)
{
	static bool playSound = ( access( "./assets/explosion.mp3", F_OK ) != -1 );

	(void)target;
	if (GameObjectManager::getPlayer() == shooter)
	{
		if (playSound)
			system("afplay ./assets/explosion.mp3 -v 0.4&");
		GameManager::increaseScore(Enemy::_pointsValue);
	}
	GameObjectManager::deleteGameObject(this);
}