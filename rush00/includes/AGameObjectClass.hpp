#ifndef AGAMEOBJECTCLASS_HPP
#define AGAMEOBJECTCLASS_HPP

#include <iostream>
#include <curses.h>

class AGameObject
{

  public:
	AGameObject(void);
	AGameObject(int x, int y);
	AGameObject(AGameObject const &src);
	virtual ~AGameObject(void) = 0;

	AGameObject &operator=(AGameObject const &rhs);

	virtual void	updatePosition(AGameObject *map[]) = 0;
	virtual void	collide(AGameObject *target) = 0;
	virtual void	collide(AGameObject *target, AGameObject const *shooter) = 0;
	std::string const toString(void) const;
	int getX(void) const;
	int getY(void) const;
	chtype getCurse(void) const;
	void setX(int x);
	void setY(int y);

protected:
	int _x;
	int _y;
	chtype _curse;
};

std::ostream &operator<<(std::ostream &o, AGameObject const &rhs);

#endif