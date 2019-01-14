#include "ProjectileClass.hpp"
#include "DisplayManagerClass.hpp"
#include "TimeClass.hpp"
#include "GameObjectManagerClass.hpp"
#include <iostream>

Projectile::Projectile(int x, int y, Direction d, int speed, AGameObject *shooter) :
_direction(d),
_secondsPerMove(1. / speed),
_shooter(shooter)
{
	this->setX(x);
	this->setY(y);
	this->_lastMoved = Time::sinceStart();
	this->_curse = (shooter == GameObjectManager::getPlayer()) ? ACS_DIAMOND : '<';
	return;
}

Projectile::~Projectile(void)
{
	return;
}

AGameObject	const *Projectile::getShooter(void) const
{
	return this->_shooter;
}

void	Projectile::collide(AGameObject *target)
{
	(void)target;
	GameObjectManager::deleteGameObject(this);
}

void	Projectile::collide(AGameObject *target, AGameObject const *shooter)
{
	(void)target;
	(void)shooter;
	GameObjectManager::deleteGameObject(this);
}

void	Projectile::updatePosition(AGameObject *map[])
{
	float now = Time::sinceStart();
	float timeDiff = now - this->_lastMoved;
	static int col = DisplayManager::getCols();
	static int row = DisplayManager::getRows();
	int newX = this->getX();
	int newY = this->getY();
	AGameObject	*target;

	if (timeDiff >= this->_secondsPerMove)
	{
		newX += this->_direction == Right ? 1 : -1;
		this->_lastMoved = now;
	}
	if (newY < 0 || newY >= row || newX < 0 || newX >= col)
	{
		GameObjectManager::deleteGameObject(this);
		return ;
	}
	if (nullptr != (target = map[newY * col + newX]))
	{
		target->collide(this, this->getShooter());
		this->collide(target);
		return ;
	}
	map[newY * col + newX] = this;
	this->setX(newX);
	this->setY(newY);
	return ;
}