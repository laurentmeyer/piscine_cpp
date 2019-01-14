#include <iostream>
#include "FragTrapClass.hpp"

int main(void)
{
	FragTrap dupont("Jean Michel Dupont");
	FragTrap dupond("Jean Michel Dupond");

	dupond = dupont;
	dupond.meleeAttack("Nadine Morano");
	dupond.rangedAttack("Jean-Francois Copé");
	for (int i = 0; i < 6; i++)
		dupond.vaulthunter_dot_exe("un méchant");

	dupond.takeDamage(12);
	dupond.beRepaired(3);
	dupond.takeDamage(1);
	dupond.takeDamage(480);

	return 0;
}