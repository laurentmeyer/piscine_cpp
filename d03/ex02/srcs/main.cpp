#include <iostream>
#include "FragTrapClass.hpp"
#include "ScavTrapClass.hpp"

int main(void)
{
	FragTrap frag("Fraggy");
	ScavTrap scav("Scatman");
	ScavTrap scopy(scav);

	frag.vaulthunter_dot_exe("un méchant");
	scav.challengeNewcomer("un sale type");

	return 0;
}