#include "FragTrapClass.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int const 		FragTrap::_initialLevel = 1;
int const 		FragTrap::_maxHitPoints = 100;
int const 		FragTrap::_maxEnergyPoints = 100;
int const 		FragTrap::_meleeAttackDamage = 30;
int const 		FragTrap::_rangedAttackDamage = 20;
int const 		FragTrap::_armorDamageReduction = 5;

FragTrap::FragTrap(void) : _name("*default name*")
{
	this->_init();
	std::cout << *this << " was created with default constructor" << std::endl;
	return;
}

FragTrap::FragTrap(std::string const name) : _name(name)
{
	this->_init();
	std::cout << *this << " was created with name constructor" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &src) : _name(src.getName())
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

void		FragTrap::_init(void)
{
	// std::srand(std::time(nullptr));
	this->_hitPoints = FragTrap::_maxHitPoints;
	this->_energyPoints = FragTrap::_maxEnergyPoints;
	this->_level = FragTrap::_initialLevel;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_level = rhs.getLevel();
	return *this;
}

std::ostream &operator<<(std::ostream &o, FragTrap const &rhs)
{
	o << "FR4G-TP " << rhs.getName();
	return o;
}

void FragTrap::setHitPoints(int hitPoints) {
	if (hitPoints < 0)
		this->_hitPoints = 0;
	else if (hitPoints > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	else
		this->_hitPoints = hitPoints;
}
void FragTrap::setEnergyPoints(int energyPoints) {
	if (energyPoints < 0)
		this->_energyPoints = 0;
	else if (energyPoints > this->_maxEnergyPoints)
		this->_energyPoints = this->_maxEnergyPoints;
	else
		this->_energyPoints = energyPoints;
}
void FragTrap::setLevel(int level) { this->_level = level; }

int FragTrap::getHitPoints(void) const { return (this->_hitPoints); }
int FragTrap::getEnergyPoints(void) const { return (this->_energyPoints); }
int FragTrap::getLevel(void) const { return (this->_level); }
std::string FragTrap::getName(void) const { return (this->_name); }

void FragTrap::_attack(std::string const &target, std::string const attackName, int attackPoints)
{
	std::cout << *this
			  << " attacks " << target
			  << " with " << attackName
			  << ", causing " << attackPoints
			  << " points of damage!" << std::endl;
	return ;
}

void FragTrap::rangedAttack(std::string const &target)
{
	this->_attack(target, "range attack", FragTrap::_rangedAttackDamage);
	return ;
}

void FragTrap::meleeAttack(std::string const &target)
{
	this->_attack(target, "melee attack", FragTrap::_meleeAttackDamage);
	return ;
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

void FragTrap::takeDamage(unsigned int amount)
{
	int damage = amount - FragTrap::_armorDamageReduction;

	if (damage < 0)
		damage = 0;
	this->setHitPoints(this->getHitPoints() - damage);
	std::cout << *this
			  << " takes " << damage
			  << " points of damage, " << this->getHitPoints()
			  << " hit points remain!" << std::endl;
	return ;
}

void FragTrap::beRepaired(unsigned int amount)
{
	this->setHitPoints(this->getHitPoints() + amount);
	std::cout << *this
			  << " is repaired for " << amount
			  << " points, " << this->getHitPoints()
			  << " hit points remain!" << std::endl;
	return ;
}