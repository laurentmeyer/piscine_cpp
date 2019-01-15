#include "InternClass.hpp"
#include <iostream>

Intern::Intern(void)
{
	return;
}

Intern::Intern(Intern const & src) 
{
	*this = src;
	return;
}

Intern::~Intern(void)
{
	return;
}

Intern &	Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return *this;
}

std::string const Intern::toString(void) const
{
	return "Some randome intern";
}

std::ostream &	operator<< (std::ostream & o, Intern const & rhs)
{
	o << rhs.toString();
	return o;
}

Form *Intern::makeForm(std::string const formName, std::string const target) const
{
	if (formName == "robotomy request")
		return new RobotomyRequestForm(target);
	if (formName == "shrubbery creation")
		return new ShrubberyCreationForm(target);
	if (formName == "presidential pardon")
		return new PresidentialPardonForm(target);
	throw Form::UnknownFormException();
}