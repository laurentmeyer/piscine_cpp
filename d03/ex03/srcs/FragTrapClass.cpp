#include "FragTrapClass.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

std::string const FragTrap::_className = "FR4G-TP";
int const 		FragTrap::_initialLevel = 1;
int const 		FragTrap::_maxHitPoints = 100;
int const 		FragTrap::_maxEnergyPoints = 100;
int const 		FragTrap::_meleeAttackDamage = 30;
int const 		FragTrap::_rangedAttackDamage = 20;
int const 		FragTrap::_armorDamageReduction = 5;

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_init();
	std::cout << *this << " was created with default constructor" << std::endl;
	return;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
	this->_init();
	std::cout << *this << " was created with name constructor" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	*this = src;
	std::cout << *this << " was created with copy constructor" << std::endl;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << *this << " was destructed" << std::endl;
	return;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_level = rhs.getLevel();
	return *this;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string const	names[5] = {"coup de boule dans les burnes", "frotte-frotte de pomme de terre sur la carotide", "coup de couteau à beurre dans le gras du bide", "jeter de MST sur les muqueuses", "enlevage des yeux et remettage dans le mauvais globe occulaire"};
	int const			hitPoints[5] = {15, 2, 37, 7, 42};
	int const			cost = 25;
	int					e;
	int					i;

	if ((e = this->getEnergyPoints()) < cost)
	{
		std::cout << "Not enough energy for a funny random attack" << std::endl;
		return ;
	}
	this->setEnergyPoints(e - cost);
	i = rand() % 5;
	this->_attack(target, names[i], hitPoints[i]);
	return ;
}

int FragTrap::_getMaxHitPoints(void) const { return FragTrap::_maxHitPoints ; }
int FragTrap::_getMaxEnergyPoints(void) const { return FragTrap::_maxEnergyPoints ; }
int FragTrap::_getInitialLevel(void) const { return FragTrap::_initialLevel ; }
int FragTrap::_getMeleeAttackDamage(void) const { return FragTrap::_meleeAttackDamage; }
int FragTrap::_getRangedAttackDamage(void) const { return FragTrap::_rangedAttackDamage; };
int FragTrap::_getArmorDamageReduction(void) const { return FragTrap::_armorDamageReduction; };
std::string FragTrap::getClassName(void) const {return FragTrap::_className; }