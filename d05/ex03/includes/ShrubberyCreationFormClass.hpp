#ifndef SHRUBBERYCREATIONFORMCLASS_HPP
#define SHRUBBERYCREATIONFORMCLASS_HPP

#include <iostream>
#include <string>
#include "FormClass.hpp"

class ShrubberyCreationForm : public Form
{

  public:
	ShrubberyCreationForm(std::string const target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

	std::string const getTarget(void) const;
	virtual void action(void) const;

  private:
	ShrubberyCreationForm(void);
	std::string const _target;
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &rhs);

#endif