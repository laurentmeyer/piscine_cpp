#ifndef CLAPTRAPCLASS_HPP
#define CLAPTRAPCLASS_HPP

#include <iostream>
#include <string>

class ClapTrap
{

  public:
	typedef ClapTrap t;

	ClapTrap 				&operator=(ClapTrap const &rhs);

	int						getHitPoints(void) const;
	int 					getEnergyPoints(void) const;
	int 					getLevel(void) const;
	std::string 			getName(void) const;
	virtual std::string		getClassName(void) const;
	std::string				toString(void) const;

	void 					setHitPoints(int hitPoints);
	void 					setEnergyPoints(int energyPoints);
	void 					setLevel(int level);
	void 					setName(std::string name);

	void					rangedAttack(std::string const & target);
	void					meleeAttack(std::string const & target);
	void					takeDamage(unsigned int amount);
	void					beRepaired(unsigned int amount);

  protected:

	ClapTrap(void);
	ClapTrap(std::string const name);
	ClapTrap(ClapTrap const &src);
	~ClapTrap(void);

	virtual int					_getMaxHitPoints(void) const;
	virtual int					_getMaxEnergyPoints(void) const;
	virtual int 				_getInitialLevel(void) const;
	virtual int					_getMeleeAttackDamage(void) const;
	virtual int					_getRangedAttackDamage(void) const;
	virtual int					_getArmorDamageReduction(void) const;
	void						_attack(std::string const &target, std::string const attackName, int attackPoints);
	void						_init();

	std::string const			_name;
	static std::string const	_className;
	int 						_level;
	int 						_hitPoints;
	int 						_energyPoints;
	static int const	 		_initialLevel;
	static int const	 		_maxHitPoints;
	static int const	 		_maxEnergyPoints;
	static int const	 		_meleeAttackDamage;
	static int const	 		_rangedAttackDamage;
	static int const	 		_armorDamageReduction;
};

std::ostream &operator<<(std::ostream &o, ClapTrap const &rhs);

#endif