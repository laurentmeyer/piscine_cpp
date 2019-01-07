#include "ZombieClass.hpp"
#include <iostream>

const std::string	Zombie::_randomNames[] = {"Nadine Morano", "Jean-Michel Apathie", "Evelyne Thomas"};

Zombie::Zombie(void) : _name(Zombie::_getRandomName())
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

std::string const Zombie::_getRandomName(void)
{
	int nb_items;

	nb_items = sizeof(Zombie::_randomNames) / sizeof(Zombie::_randomNames[0]);
	return (Zombie::_randomNames[std::rand() % nb_items]);
}