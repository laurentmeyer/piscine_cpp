#include "BureaucratClass.hpp"
#include <iostream>

unsigned int const Bureaucrat::_maxGrade = 1;
unsigned int const Bureaucrat::_minGrade = 150;

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
	this->_setGrade(grade);
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	return;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->_grade = rhs.getGrade();
	return *this;
}

std::string const Bureaucrat::toString(void) const
{
	return this->getName() + ", bureaucrate grade " + std::to_string(this->getGrade());
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.toString();
	return o;
}
unsigned int Bureaucrat::getGrade(void) const { return (this->_grade); }

void Bureaucrat::_setGrade(unsigned int grade)
{
	if (grade < Bureaucrat::_maxGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > Bureaucrat::_minGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

std::string const Bureaucrat::getName(void) const { return (this->_name); }
void Bureaucrat::promote(void)
{
	this->_setGrade(this->getGrade() - 1);
	std::cout << *this << " got promoted, congrats!" << std::endl;
}

void Bureaucrat::retrograde(void)
{
	this->_setGrade(this->getGrade() + 1);
	std::cout << *this << " got retrograded, loser!" << std::endl;
}

void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << *this << ", signs " << f << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << *this << ", cannot sign " << f << ". Error reason: " << e.what() << std::endl;
	}
}

unsigned int Bureaucrat::getMinGrade (void) { return Bureaucrat::_minGrade; }
unsigned int Bureaucrat::getMaxGrade (void) { return Bureaucrat::_maxGrade; }

Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}
char const *Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low exception"; }
Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(Bureaucrat::GradeTooLowException const &rhs)
{
	(void)rhs;
	return *this;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}
char const *Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high exception"; }
Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(Bureaucrat::GradeTooHighException const &rhs)
{
	(void)rhs;
	return *this;
}