#include "ScavTrapClass.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int const 		ScavTrap::_initialLevel = 1;
int const 		ScavTrap::_maxHitPoints = 100;
int const 		ScavTrap::_maxEnergyPoints = 50;
int const 		ScavTrap::_meleeAttackDamage = 20;
int const 		ScavTrap::_rangedAttackDamage = 15;
int const 		ScavTrap::_armorDamageReduction = 3;

ScavTrap::ScavTrap(void) : _name("*default name*")
{
	this->_init();
	std::cout << *this << " was created with default constructor" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string const name) : _name(name)
{
	this->_init();
	std::cout << *this << " was created with name constructor" << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &src) : _name(src.getName())
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

void		ScavTrap::_init(void)
{
	// std::srand(std::time(nullptr));
	this->_hitPoints = ScavTrap::_maxHitPoints;
	this->_energyPoints = ScavTrap::_maxEnergyPoints;
	this->_level = ScavTrap::_initialLevel;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_level = rhs.getLevel();
	return *this;
}

std::ostream &operator<<(std::ostream &o, ScavTrap const &rhs)
{
	o << "SC4V-TP " << rhs.getName();
	return o;
}

void ScavTrap::setHitPoints(int hitPoints) {
	if (hitPoints < 0)
		this->_hitPoints = 0;
	else if (hitPoints > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	else
		this->_hitPoints = hitPoints;
}
void ScavTrap::setEnergyPoints(int energyPoints) {
	if (energyPoints < 0)
		this->_energyPoints = 0;
	else if (energyPoints > this->_maxEnergyPoints)
		this->_energyPoints = this->_maxEnergyPoints;
	else
		this->_energyPoints = energyPoints;
}
void ScavTrap::setLevel(int level) { this->_level = level; }

int ScavTrap::getHitPoints(void) const { return (this->_hitPoints); }
int ScavTrap::getEnergyPoints(void) const { return (this->_energyPoints); }
int ScavTrap::getLevel(void) const { return (this->_level); }
std::string ScavTrap::getName(void) const { return (this->_name); }

void ScavTrap::_attack(std::string const &target, std::string const attackName, int attackPoints)
{
	std::cout << *this
			  << " attacks " << target
			  << " with " << attackName
			  << ", causing " << attackPoints
			  << " points of damage!" << std::endl;
	return ;
}

void ScavTrap::rangedAttack(std::string const &target)
{
	this->_attack(target, "range attack", ScavTrap::_rangedAttackDamage);
	return ;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	this->_attack(target, "melee attack", ScavTrap::_meleeAttackDamage);
	return ;
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

void ScavTrap::takeDamage(unsigned int amount)
{
	int damage = amount - ScavTrap::_armorDamageReduction;

	if (damage < 0)
		damage = 0;
	this->setHitPoints(this->getHitPoints() - damage);
	std::cout << *this
			  << " takes " << damage
			  << " points of damage, " << this->getHitPoints()
			  << " hit points remain!" << std::endl;
	return ;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	this->setHitPoints(this->getHitPoints() + amount);
	std::cout << *this
			  << " is repaired for " << amount
			  << " points, " << this->getHitPoints()
			  << " hit points remain!" << std::endl;
	return ;
}