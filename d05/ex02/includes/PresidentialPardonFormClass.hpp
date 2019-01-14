#ifndef PRESIDENTIALPARDONFORMCLASS_HPP
#define PRESIDENTIALPARDONFORMCLASS_HPP

#include <iostream>
#include <string>
#include "AFormClass.hpp"

class PresidentialPardonForm : public AForm
{
  public:

	PresidentialPardonForm(std::string const target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	~PresidentialPardonForm(void);

	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

	std::string const getTarget(void) const;
	virtual void action(void) const;

  private:
	PresidentialPardonForm(void);
	std::string const _target;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &rhs);

#endif