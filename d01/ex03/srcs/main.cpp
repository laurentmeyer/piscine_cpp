#include <iostream>
#include "ZombieClass.hpp"
#include "ZombieHordeClass.hpp"

int main(void)
{
	ZombieHorde	*horde = new ZombieHorde(12);
	horde->announce();
	std::cout << std::endl;
	delete horde;
	return (0);
}