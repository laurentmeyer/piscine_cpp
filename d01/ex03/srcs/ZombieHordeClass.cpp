#include "ZombieHordeClass.hpp"
#include <ctime>

ZombieHorde::ZombieHorde(int n) : _n(n) {
	std::srand(std::time(nullptr));
	this->_horde = new Zombie[n];
	return;
}

ZombieHorde::~ZombieHorde(void) {
	delete[] this->_horde;
	return;
}

void ZombieHorde::announce(void) const
{
	for (int i = 0; i < this->_n; i++)
		_horde[i].announce();
}