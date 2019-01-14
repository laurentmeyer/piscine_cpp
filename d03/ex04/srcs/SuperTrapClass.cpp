#include "SuperTrapClass.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

std::string const SuperTrap::_className = "SUP3R-TP";
int const 		SuperTrap::_initialLevel = 1;
int const 		SuperTrap::_maxHitPoints = FragTrap::_maxHitPoints;
int const 		SuperTrap::_maxEnergyPoints = NinjaTrap::_maxEnergyPoints;
int const 		SuperTrap::_meleeAttackDamage = NinjaTrap::_meleeAttackDamage;
int const 		SuperTrap::_rangedAttackDamage = FragTrap::_rangedAttackDamage;
int const 		SuperTrap::_armorDamageReduction = FragTrap::_armorDamageReduction;

SuperTrap::SuperTrap(void) : ClapTrap()
{
	this->_init();
	std::cout << *this << " was created with default constructor" << std::endl;
	return;
}

SuperTrap::SuperTrap(std::string const name) : ClapTrap(name)
{
	this->_init();
	std::cout << *this << " was created with name constructor" << std::endl;
	return;
}

SuperTrap::SuperTrap(SuperTrap const &src) : ClapTrap(src)
{
	*this = src;
	std::cout << *this << " was created with copy constructor" << std::endl;
	return;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << *this << " was destructed" << std::endl;
	return;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &rhs)
{
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_level = rhs.getLevel();
	return *this;
}

int SuperTrap::_getMaxHitPoints(void) const { return SuperTrap::_maxHitPoints ; }
int SuperTrap::_getMaxEnergyPoints(void) const { return SuperTrap::_maxEnergyPoints ; }
int SuperTrap::_getInitialLevel(void) const { return SuperTrap::_initialLevel ; }
int SuperTrap::_getMeleeAttackDamage(void) const { return SuperTrap::_meleeAttackDamage; }
int SuperTrap::_getRangedAttackDamage(void) const { return SuperTrap::_rangedAttackDamage; };
int SuperTrap::_getArmorDamageReduction(void) const { return SuperTrap::_armorDamageReduction; };
std::string SuperTrap::getClassName(void) const {return SuperTrap::_className; }