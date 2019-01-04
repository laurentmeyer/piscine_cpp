#ifndef PONYCLASS_HPP
# define PONYCLASS_HPP

# include <string>

class Pony {

public: 

	typedef Pony	t;
	Pony(void); 
	Pony(std::string noise); 
	~Pony(void);

	int		getLegs(void) const;
	void	setLegs(int legs);

private:

	int					_legs;
	std::string	const	_noise;

};


#endif