#ifndef PLAYERCLASS_HPP
#define PLAYERCLASS_HPP

#include <iostream>
#include "AGameObjectClass.hpp"

class Player : public AGameObject
{

  public:
	Player(void);
	Player(int x, int y);
	~Player(void);

	std::string const toString(void) const;
	std::string getName(void) const;
	void setName(std::string name);
	virtual void	updatePosition(AGameObject *map[]);
	virtual void			collide(AGameObject *target);
	virtual void			collide(AGameObject *target, AGameObject const *shooter);

  private:
	Player(Player const &src);
	Player &operator=(Player const &rhs);

	std::string _name;
};

std::ostream &operator<<(std::ostream &o, Player const &rhs);

#endif