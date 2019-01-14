#include <iostream>
#include "ScavTrapClass.hpp"

int main(void)
{
	ScavTrap dupont("Jean François Dupont");
	ScavTrap dupond("Jean François Dupond");

	dupond = dupont;
	dupond.meleeAttack("Nadine Morano");
	dupond.rangedAttack("Jean-Francois Copé");
	for (int i = 0; i < 10; i++)
		dupond.challengeNewcomer("un méchant");

	dupond.takeDamage(12);
	dupond.beRepaired(3);
	dupond.takeDamage(1);
	dupond.takeDamage(480);

	return 0;
}