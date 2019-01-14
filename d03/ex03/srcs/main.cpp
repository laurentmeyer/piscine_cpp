#include <iostream>
#include "FragTrapClass.hpp"
#include "ScavTrapClass.hpp"
#include "NinjaTrapClass.hpp"

int main(void)
{
	FragTrap frag("Fraggy");
	ScavTrap scav("Scatman");
	NinjaTrap black_ninja("Philippe");

	frag.vaulthunter_dot_exe("un méchant");
	scav.challengeNewcomer("un sale type");
	black_ninja.ninjaShoebox(frag);
	black_ninja.ninjaShoebox(scav);
	black_ninja.ninjaShoebox(black_ninja);


	return 0;
}