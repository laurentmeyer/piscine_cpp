#include "ScavTrapClass.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

std::string const ScavTrap::_className = "SC4V-TP";
int const 		ScavTrap::_initialLevel = 1;
int const 		ScavTrap::_maxHitPoints = 100;
int const 		ScavTrap::_maxEnergyPoints = 50;
int const 		ScavTrap::_meleeAttackDamage = 20;
int const 		ScavTrap::_rangedAttackDamage = 15;
int const 		ScavTrap::_armorDamageReduction = 3;

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_init();
	std::cout << *this << " was created with default constructor" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name)
{
	this->_init();
	std::cout << *this << " was created with name constructor" << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	*this = src;
	std::cout << *this << " was created with copy constructor" << std::endl;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << *this << " was destructed" << std::endl;
	return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_level = rhs.getLevel();
	return *this;
}

void	ScavTrap::challengeNewcomer(std::string const & target)
{
	std::string const	challenges[5] = {
		"mange un sandwich beurre de cacahuète et ketchup",
		"épile intégralement un chat à la pince à épiler",
		"lèche la barre sur la ligne 13 du métro",
		"écoute une mixtape de Jul. Sous acide.",
		"habille toi en combinaison de latex intégral et va au spectacle de Guignol, tout seul"};

	std::cout << target << ", your challenge is: " << challenges[rand() % 5] << std::endl;
	return ;
}

int ScavTrap::_getMaxHitPoints(void) const { return ScavTrap::_maxHitPoints ; }
int ScavTrap::_getMaxEnergyPoints(void) const { return ScavTrap::_maxEnergyPoints ; }
int ScavTrap::_getInitialLevel(void) const { return ScavTrap::_initialLevel ; }
int ScavTrap::_getMeleeAttackDamage(void) const { return ScavTrap::_meleeAttackDamage; }
int ScavTrap::_getRangedAttackDamage(void) const { return ScavTrap::_rangedAttackDamage; };
int ScavTrap::_getArmorDamageReduction(void) const { return ScavTrap::_armorDamageReduction; };
std::string ScavTrap::getClassName(void) const {return ScavTrap::_className; }