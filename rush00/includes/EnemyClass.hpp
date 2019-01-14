#ifndef ENEMYCLASS_HPP
#define ENEMYCLASS_HPP

#include <iostream>
#include "AGameObjectClass.hpp"
#include "ProjectileClass.hpp"
#include "DisplayManagerClass.hpp"

class Enemy : public AGameObject
{

  public:
	Enemy(int x, int y);
	~Enemy(void);

	std::string const toString(void) const;
	void update(void);
	virtual void updatePosition(AGameObject *map[]);
	virtual void			collide(AGameObject *target);
	virtual void			collide(AGameObject *target, AGameObject const *shooter);

  private:
	Enemy(void);
	Enemy(Enemy const &src);
	Enemy &operator=(Enemy const &rhs);

	void			_shoot(void);

	static int const	_pointsValue;
	float 				_lastMoved;
	float const 		_secondsPerMove;
	float 				_lastShot;
	float const 		_secondsPerShot;
};

std::ostream &operator<<(std::ostream &o, Enemy const &rhs);

#endif