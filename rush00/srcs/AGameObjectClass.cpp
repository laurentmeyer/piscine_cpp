#include "AGameObjectClass.hpp"
#include <iostream>

AGameObject::AGameObject(void) : _x(0), _y(0)
{
	return;
}

AGameObject::AGameObject(int x, int y) : _x(x), _y(y)
{
	return;
}

AGameObject::AGameObject(AGameObject const &src)
{
	*this = src;
	return;
}

AGameObject::~AGameObject(void)
{
	return;
}

AGameObject &AGameObject::operator=(AGameObject const &rhs)
{
	this->setX(rhs.getX());
	this->setY(rhs.getY());
	return *this;
}

std::string const AGameObject::toString(void) const
{
	return "AGameObject at position " + std::to_string(this->getX()) + ", " + std::to_string(this->getY());
}

std::ostream &operator<<(std::ostream &o, AGameObject const &rhs)
{
	o << rhs.toString();
	return o;
}
int AGameObject::getY(void) const { return (this->_y); }
void AGameObject::setY(int y) { this->_y = y; }

int AGameObject::getX(void) const { return (this->_x); }
void AGameObject::setX(int x) { this->_x = x; }
chtype		AGameObject::getCurse(void) const { return this->_curse ; }