#ifndef SCAVTRAPCLASS_HPP
#define SCAVTRAPCLASS_HPP

#include <iostream>
#include <string>
#include "ClapTrapClass.hpp"

class ScavTrap : public	ClapTrap
{

  public:
	typedef ScavTrap t;
	ScavTrap(std::string const name);
	ScavTrap(ScavTrap const &src);
	~ScavTrap(void);

	ScavTrap 				&operator=(ScavTrap const &rhs);
	virtual std::string		getClassName(void) const;
	void					challengeNewcomer(std::string const & target);

  protected:

	ScavTrap(void);

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