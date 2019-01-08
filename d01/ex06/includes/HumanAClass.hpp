#ifndef HUMANACLASS_HPP
# define HUMANACLASS_HPP

# include <string>
# include <iostream>
# include "WeaponClass.hpp"

class HumanA {

public: 

	typedef HumanA	t;
	HumanA(std::string name, Weapon &weapon); 
	~HumanA(void); 

	void			attack(void) const;
	void			setWeapon(Weapon &weapon);

private:

	std::string		_name;
	Weapon			&_weapon;


};


#endif