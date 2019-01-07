#ifndef ZOMBIECLASS_HPP
# define ZOMBIECLASS_HPP

# include <string>

class Zombie {

public: 

	typedef Zombie	t;
	Zombie(void); 
	~Zombie(void); 


	void 		setType(std::string type);
	std::string	toString(void);
	void		announce(void);

  private:
	static std::string const	_getRandomName();

	std::string 				_type;
	std::string const			_name;
	static std::string const	_randomNames[];
};

#endif