#ifndef ZOMBIEEVENTCLASS_HPP
# define ZOMBIEEVENTCLASS_HPP

# include "ZombieClass.hpp"
# include <string>

class ZombieEvent {

public: 

	typedef ZombieEvent	t;
	ZombieEvent(void); 
	~ZombieEvent(void); 

	static Zombie		*newZombie(std::string name);
	static void			setZombieType(Zombie *zombie, std::string type);
	static Zombie		*randomChump();

private:
	static const std::string	_random_names[];

};


#endif