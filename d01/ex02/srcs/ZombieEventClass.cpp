#include "ZombieEventClass.hpp"
#include <ctime>
#include <iostream>

const std::string	ZombieEvent::_random_names[] = {"Nadine Morano", "Jean-Michel Apathie", "Evelyne Thomas"};

ZombieEvent::ZombieEvent(void)
{
	return;
}

ZombieEvent::~ZombieEvent(void)
{
	return;
}

void ZombieEvent::setZombieType(Zombie *zombie, std::string type)
{
	zombie->setType(type);
}

Zombie		*ZombieEvent::newZombie(std::string name)
{
	Zombie	*zombie = new Zombie(name);
	return (zombie);
}

Zombie		*ZombieEvent::randomChump()
{
	int nb_items;
	Zombie *chump;

	std::srand(std::time(nullptr));
	nb_items = sizeof(ZombieEvent::_random_names) / sizeof(ZombieEvent::_random_names[0]);
	chump = ZombieEvent::newZombie(ZombieEvent::_random_names[std::rand() % nb_items]);
	ZombieEvent::setZombieType(chump, "random");
	return(chump);
}