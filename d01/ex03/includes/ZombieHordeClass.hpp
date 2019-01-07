#ifndef ZOMBIEHORDECLASS_HPP
# define ZOMBIEHORDECLASS_HPP

# include "ZombieClass.hpp"

class ZombieHorde {

public: 

	typedef ZombieHorde	t;
	ZombieHorde(int n); 
	~ZombieHorde(void); 

	void	announce(void) const;

private:
	int const	_n;
	Zombie		*_horde;

};


#endif