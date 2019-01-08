#ifndef HUMANBCLASS_HPP
# define HUMANBCLASS_HPP

# include <string>
# include <iostream>
# include "WeaponClass.hpp"

class HumanB {

public: 

	typedef HumanB	t;
	HumanB(std::string name); 
	~HumanB(void); 

	void			attack(void) const;
	void			setWeapon(Weapon &weapon);

private:

	HumanB(void); 
	std::string		_name;
	Weapon			*_weapon;
	// we have to use a pointer here because there is no default constructor for Weapons

};


#endif