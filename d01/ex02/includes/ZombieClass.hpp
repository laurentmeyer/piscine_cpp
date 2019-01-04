#ifndef ZOMBIECLASS_HPP
# define ZOMBIECLASS_HPP

# include <string>

class Zombie {

public: 

	typedef Zombie	t;
	Zombie(std::string name); 
	~Zombie(void); 


	void 		setType(std::string type);
	std::string	toString(void);
	void		announce(void);

  private:
	std::string 		_type;
	std::string const	_name;
};

#endif