#ifndef PROJECTILECLASS_HPP
# define PROJECTILECLASS_HPP

# include <iostream>
# include "AGameObjectClass.hpp"

class Projectile : public AGameObject {

public: 

	enum Direction { Left, Right };

	Projectile(int x, int y, Direction d, int speed, AGameObject *shooter); 
	~Projectile(void); 

	virtual void			updatePosition(AGameObject *map[]);
	virtual void			collide(AGameObject *target);
	virtual void			collide(AGameObject *target, AGameObject const *shooter);
	AGameObject const		*getShooter(void) const;

private:
	Projectile(void); 
	Projectile(Projectile const & src); 
	Projectile &		operator=(Projectile const & rhs);


	Direction const		_direction;
	float				_lastMoved;
	float const			_secondsPerMove;
	AGameObject const	*_shooter;

};

#endif