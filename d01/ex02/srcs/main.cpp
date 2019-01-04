#include <iostream>
#include "ZombieClass.hpp"
#include "ZombieEventClass.hpp"

int main(void)
{
	ZombieEvent	factory;
	Zombie		zombieOnTheStack = Zombie("JeanFion");
	Zombie		*createdOnHeap = ZombieEvent::newZombie("Seth Guecko");
	Zombie		*randomOnHeap = ZombieEvent::randomChump();

	zombieOnTheStack.announce();
	createdOnHeap->announce();
	randomOnHeap->announce();
	delete createdOnHeap;
	delete randomOnHeap;

	return (0);
}