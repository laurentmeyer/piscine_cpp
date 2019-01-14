#include "NinjaTrapClass.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

std::string const NinjaTrap::_className = "NINJ4-TP";
int const 		NinjaTrap::_initialLevel = 1;
int const 		NinjaTrap::_maxHitPoints = 60;
int const 		NinjaTrap::_maxEnergyPoints = 120;
int const 		NinjaTrap::_meleeAttackDamage = 60;
int const 		NinjaTrap::_rangedAttackDamage = 5;
int const 		NinjaTrap::_armorDamageReduction = 0;

NinjaTrap::NinjaTrap(void) : ClapTrap()
{
	this->_init();
	std::cout << *this << " was created with default constructor" << std::endl;
	return;
}

NinjaTrap::NinjaTrap(std::string const name) : ClapTrap(name)
{
	this->_init();
	std::cout << *this << " was created with name constructor" << std::endl;
	return;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) : ClapTrap(src)
{
	*this = src;
	std::cout << *this << " was created with copy constructor" << std::endl;
	return;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << *this << " was destructed" << std::endl;
	return;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &rhs)
{
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_level = rhs.getLevel();
	return *this;
}

void	NinjaTrap::ninjaShoebox(FragTrap & target)
{
	std::cout << *this << " says: UZ is the king of trap, I kill you now, " << target << std::endl;
	return ;
}

void	NinjaTrap::ninjaShoebox(ScavTrap & target)
{
	std::cout << *this << " says: " << target << " is a Scavman, padabadaba Pim pam pam padapoum, pam pam padadoum !" << std::endl;
	return ;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap & target)
{
	std::cout << *this << " says: " << target << ", reviens ici que je te bute, enculé !" << std::endl;
	return ;
}

int NinjaTrap::_getMaxHitPoints(void) const { return NinjaTrap::_maxHitPoints ; }
int NinjaTrap::_getMaxEnergyPoints(void) const { return NinjaTrap::_maxEnergyPoints ; }
int NinjaTrap::_getInitialLevel(void) const { return NinjaTrap::_initialLevel ; }
int NinjaTrap::_getMeleeAttackDamage(void) const { return NinjaTrap::_meleeAttackDamage; }
int NinjaTrap::_getRangedAttackDamage(void) const { return NinjaTrap::_rangedAttackDamage; };
int NinjaTrap::_getArmorDamageReduction(void) const { return NinjaTrap::_armorDamageReduction; };
std::string NinjaTrap::getClassName(void) const {return NinjaTrap::_className; }