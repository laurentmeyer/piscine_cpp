#ifndef FRAGTRAPCLASS_HPP
#define FRAGTRAPCLASS_HPP

#include <iostream>
#include <string>
#include "ClapTrapClass.hpp"

class FragTrap : public	ClapTrap
{

  public:
	typedef FragTrap t;
	FragTrap(std::string const name);
	FragTrap(FragTrap const &src);
	~FragTrap(void);

	FragTrap 				&operator=(FragTrap const &rhs);
	virtual std::string		getClassName(void) const;

	void					vaulthunter_dot_exe(std::string const & target);

  protected:

	FragTrap(void);

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