#ifndef FRAGTRAPCLASS_HPP
#define FRAGTRAPCLASS_HPP

#include <iostream>
#include <string>

class FragTrap
{

  public:
	typedef FragTrap t;
	FragTrap(std::string const name);
	FragTrap(FragTrap const &src);
	~FragTrap(void);

	FragTrap 				&operator=(FragTrap const &rhs);

	int						getHitPoints(void) const;
	int 					getEnergyPoints(void) const;
	int 					getLevel(void) const;
	std::string 			getName(void) const;

	void 					setHitPoints(int hitPoints);
	void 					setEnergyPoints(int energyPoints);
	void 					setLevel(int level);
	void 					setName(std::string name);

	void					rangedAttack(std::string const & target);
	void					meleeAttack(std::string const & target);
	void					vaulthunter_dot_exe(std::string const & target);
	void					takeDamage(unsigned int amount);
	void					beRepaired(unsigned int amount);

  private:

	FragTrap(void);

	void					_attack(std::string const &target, std::string const attackName, int attackPoints);
	void					_init();

	std::string const		_name;
	int 					_level;
	int 					_hitPoints;
	int 					_energyPoints;
	static int const 		_initialLevel;
	static int const 		_maxHitPoints;
	static int const 		_maxEnergyPoints;
	static int const 		_meleeAttackDamage;
	static int const 		_rangedAttackDamage;
	static int const 		_armorDamageReduction;
};

std::ostream &operator<<(std::ostream &o, FragTrap const &rhs);

#endif