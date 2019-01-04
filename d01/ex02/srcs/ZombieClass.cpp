#include "ZombieClass.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name)
{
	this->_type = "created";
	return;
}

Zombie::~Zombie(void)
{
	std::cout << this->toString() << " just got destroyed. Buh bye!" << std::endl;
	return;
}

void 		Zombie::setType(std::string type) { this->_type = type; }

std::string Zombie::toString(void)
{
	return ("<" + this->_name + " (" + this->_type + ")>");
}

void Zombie::announce(void)
{
	std::cout << this->toString() << " Braiiiiiiinnnssss..." << std::endl;
}