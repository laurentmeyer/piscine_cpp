#include "RobotomyRequestFormClass.hpp"
#include <iostream>
#include <fstream>
#include <time.h>


RobotomyRequestForm::RobotomyRequestForm(std::string const target) :
AForm("Robotomy Request", 72, 45),
_target(target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src)
{
	*this = src;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	(void)rhs;
	return *this;
}

std::ostream &	operator<< (std::ostream & o, RobotomyRequestForm const & rhs)
{
	o << rhs.toString();
	return o;
}

void RobotomyRequestForm::action(void) const
{
	if (std::rand() % 2)
		throw RobotomyRequestForm::RobotomyFailureException();
	std::cout << this->getTarget() << " has been successfully robotomized" << std::endl;
}

std::string const RobotomyRequestForm::getTarget(void) const { return (this->_target); }

RobotomyRequestForm::RobotomyFailureException::RobotomyFailureException(void) {}
RobotomyRequestForm::RobotomyFailureException::~RobotomyFailureException(void) throw() {}
char const *RobotomyRequestForm::RobotomyFailureException::what() const throw() { return "Robotomy failed"; }
RobotomyRequestForm::RobotomyFailureException &RobotomyRequestForm::RobotomyFailureException::operator=(RobotomyRequestForm::RobotomyFailureException const &rhs)
{
	(void)rhs;
	return *this;
}