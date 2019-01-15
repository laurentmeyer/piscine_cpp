#ifndef INTERNCLASS_HPP
# define INTERNCLASS_HPP

# include <iostream>
# include <string>
# include "FormClass.hpp"
# include "RobotomyRequestFormClass.hpp"
# include "PresidentialPardonFormClass.hpp"
# include "ShrubberyCreationFormClass.hpp"

class Intern {

public: 

	Intern(void); 
	Intern(Intern const & src); 
	~Intern(void); 

	Intern &		operator=(Intern const & rhs);

	std::string const	toString(void) const;
	Form				*makeForm(std::string const formName, std::string const target) const;


private:

};

std::ostream &	operator<< (std::ostream & o, Intern const & rhs);

#endif