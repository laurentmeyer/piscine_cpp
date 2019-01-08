#ifndef WEAPONCLASS_HPP
# define WEAPONCLASS_HPP

# include <string>

class Weapon {

public: 

	typedef Weapon	t;
	Weapon(std::string type); 
	~Weapon(void); 

	std::string const		&getType(void) const;
	void					setType(std::string type);

private:

	std::string 			_type;

};


#endif