#include "PresidentialPardonFormClass.hpp"
#include <iostream>
#include <fstream>
#include <time.h>


PresidentialPardonForm::PresidentialPardonForm(std::string const target) :
Form("Presidential Pardon", 25, 5),
_target(target)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : Form(src)
{
	*this = src;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	(void)rhs;
	return *this;
}

std::ostream &	operator<< (std::ostream & o, PresidentialPardonForm const & rhs)
{
	o << rhs.toString();
	return o;
}

void PresidentialPardonForm::action(void) const
{
	std::cout << this->getTarget() << "  has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string const PresidentialPardonForm::getTarget(void) const { return (this->_target); }