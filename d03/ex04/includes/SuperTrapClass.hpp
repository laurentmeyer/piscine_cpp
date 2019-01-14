#ifndef SUPERTRAPCLASS_HPP
#define SUPERTRAPCLASS_HPP

#include <iostream>
#include <string>
#include "ClapTrapClass.hpp"
#include "FragTrapClass.hpp"
#include "ScavTrapClass.hpp"
#include "NinjaTrapClass.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{

  public:
	typedef SuperTrap t;
	SuperTrap(std::string const name);
	SuperTrap(SuperTrap const &src);
	~SuperTrap(void);

	SuperTrap 				&operator=(SuperTrap const &rhs);
	virtual std::string		getClassName(void) const;

  protected:

	SuperTrap(void);

	virtual int				_getMaxHitPoints(void) const;
	virtual int 			_getMaxEnergyPoints(void) const;
	virtual int 			_getInitialLevel(void) const;
	virtual int 			_getMeleeAttackDamage(void) const;
	virtual int 			_getRangedAttackDamage(void) const;
	virtual int 			_getArmorDamageReduction(void) const;

	std::string const		_name;
	int 					_level;
	int 					_hitPoints;
	int 					_energyPoints;
	static std::string const	_className;
	static int const 		_initialLevel;
	static int const 		_maxHitPoints;
	static int const 		_maxEnergyPoints;
	static int const 		_meleeAttackDamage;
	static int const 		_rangedAttackDamage;
	static int const 		_armorDamageReduction;
};

#endif