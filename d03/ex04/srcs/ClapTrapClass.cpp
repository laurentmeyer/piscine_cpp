#include "ClapTrapClass.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

std::string const ClapTrap::_className = "CL4P-TP";
int const 		ClapTrap::_initialLevel = 0;
int const 		ClapTrap::_maxHitPoints = 0;
int const 		ClapTrap::_maxEnergyPoints = 0;
int const 		ClapTrap::_meleeAttackDamage = 0;
int const 		ClapTrap::_rangedAttackDamage = 0;
int const 		ClapTrap::_armorDamageReduction = 0;

ClapTrap::ClapTrap(void) : _name("*default name*")
{
	std::cout << *this << " was created with default constructor" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string const name) : _name(name)
{
	std::cout << *this << " was created with name constructor" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &src) : _name(src.getName())
{
	std::cout << *this << " was created with copy constructor" << std::endl;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << *this << " was destructed" << std::endl;
	return;
}

void		ClapTrap::_init(void)
{
	this->_hitPoints = this->_getMaxHitPoints();
	this->_energyPoints = this->_getMaxEnergyPoints();
	this->_level = this->_getInitialLevel();
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_level = rhs.getLevel();
	return *this;
}

std::string		ClapTrap::toString(void) const
{
	return this->getClassName() + " " + this->getName();

}

std::ostream &operator<<(std::ostream &o, ClapTrap const &rhs)
{
	o << rhs.toString();
	return o;
}

void ClapTrap::setHitPoints(int hitPoints) {
	if (hitPoints < 0)
		this->_hitPoints = 0;
	else if (hitPoints > this->_getMaxHitPoints())
		this->_hitPoints = this->_getMaxHitPoints();
	else
		this->_hitPoints = hitPoints;
}
void ClapTrap::setEnergyPoints(int energyPoints) {
	if (energyPoints < 0)
		this->_energyPoints = 0;
	else if (energyPoints > this->_getMaxEnergyPoints())
		this->_energyPoints = this->_getMaxEnergyPoints();
	else
		this->_energyPoints = energyPoints;
}
void ClapTrap::setLevel(int level) { this->_level = level; }

int ClapTrap::getHitPoints(void) const { return (this->_hitPoints); }
int ClapTrap::getEnergyPoints(void) const { return (this->_energyPoints); }
int ClapTrap::getLevel(void) const { return (this->_level); }
std::string ClapTrap::getName(void) const { return (this->_name); }
std::string ClapTrap::getClassName(void) const {return ClapTrap::_className; }
int ClapTrap::_getMaxHitPoints(void) const { return ClapTrap::_maxHitPoints ; }
int ClapTrap::_getMaxEnergyPoints(void) const { return ClapTrap::_maxEnergyPoints ; }
int ClapTrap::_getInitialLevel(void) const { return ClapTrap::_initialLevel ; }
int ClapTrap::_getMeleeAttackDamage(void) const { return ClapTrap::_meleeAttackDamage; }
int ClapTrap::_getRangedAttackDamage(void) const { return ClapTrap::_rangedAttackDamage; };
int ClapTrap::_getArmorDamageReduction(void) const { return ClapTrap::_armorDamageReduction; };

void ClapTrap::_attack(std::string const &target, std::string const attackName, int attackPoints)
{
	std::cout << *this
			  << " attacks " << target
			  << " with " << attackName
			  << ", causing " << attackPoints
			  << " points of damage!" << std::endl;
	return ;
}

void ClapTrap::rangedAttack(std::string const &target)
{
	this->_attack(target, "range attack", this->_getRangedAttackDamage());
	return ;
}

void ClapTrap::meleeAttack(std::string const &target)
{
	this->_attack(target, "melee attack", this->_getMeleeAttackDamage());
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int damage = amount - ClapTrap::_armorDamageReduction;

	if (damage < 0)
		damage = 0;
	this->setHitPoints(this->getHitPoints() - damage);
	std::cout << *this
			  << " takes " << damage
			  << " points of damage, " << this->getHitPoints()
			  << " hit points remain!" << std::endl;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->setHitPoints(this->getHitPoints() + amount);
	std::cout << *this
			  << " is repaired for " << amount
			  << " points, " << this->getHitPoints()
			  << " hit points remain!" << std::endl;
	return ;
}