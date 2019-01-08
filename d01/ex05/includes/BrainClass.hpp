#ifndef BRAINCLASS_HPP
# define BRAINCLASS_HPP

# include <string>

class Brain {

public: 

	typedef Brain	t;
	Brain(void); 
	~Brain(void); 

	std::string		identify(void) const;


private:

};


#endif