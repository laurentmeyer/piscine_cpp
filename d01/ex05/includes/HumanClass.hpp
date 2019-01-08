#ifndef HUMANCLASS_HPP
# define HUMANCLASS_HPP

# include <string>
# include "BrainClass.hpp"

class Human {

public: 

	typedef Human	t;
	Human(void); 
	~Human(void); 

	std::string		identify(void) const;
	Brain			&getBrain(void);


private:

	Brain	_brain;

};


#endif