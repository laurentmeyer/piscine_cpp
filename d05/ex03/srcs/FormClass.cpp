#include "FormClass.hpp"
#include <iostream>
#include <sstream>

Form::Form(std::string const name, unsigned int minSignature, unsigned int minExecution) :
_minGradeExecute(minExecution),
_minGradeSign(minSignature),
_name(name)
{
	if (this->_minGradeSign > Bureaucrat::getMinGrade() || this->_minGradeExecute > Bureaucrat::getMinGrade())
		throw Form::GradeTooLowException();
	if (this->_minGradeSign < Bureaucrat::getMaxGrade() || this->_minGradeExecute < Bureaucrat::getMaxGrade())
		throw Form::GradeTooHighException();
	this->_setSigned(false);
	return;
}

Form::Form(Form const &src) :
_minGradeExecute(src.getMinGradeExecute()),
_minGradeSign(src.getMinGradeSign())
{
	if (this->_minGradeSign > Bureaucrat::getMinGrade() || this->_minGradeExecute > Bureaucrat::getMinGrade())
		throw Form::GradeTooLowException();
	if (this->_minGradeSign < Bureaucrat::getMaxGrade() || this->_minGradeExecute < Bureaucrat::getMaxGrade())
		throw Form::GradeTooHighException();
	this->_setSigned(src.getSigned());
	*this = src;
	return;
}

Form::~Form(void)
{
	return;
}

Form &Form::operator=(Form const &rhs)
{
	(void)rhs;
	return *this;
}

std::string const Form::toString(void) const
{
	std::ostringstream s;

	s << (this->_signed ? "signed" : "unsigned") << " form " << this->getName()
		<< ", grade " << this->getMinGradeSign() << " to sign"
		<< ", grade " << this->getMinGradeExecute() << " to execute";
	return s.str();
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << rhs.toString();
	return o;
}

bool Form::getSigned(void) const { return (this->_signed); }
unsigned int Form::getMinGradeSign(void) const { return (this->_minGradeSign); }
unsigned int Form::getMinGradeExecute(void) const { return (this->_minGradeExecute); }
std::string const	Form::getName (void) const { return (this->_name); }

void Form::_setSigned(bool s) { this->_signed = s; }

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->getMinGradeSign())
		throw Form::GradeTooLowException();
	this->_setSigned(true);
}

void Form::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw Form::FormNotSignedException();
	if (executor.getGrade() > this->getMinGradeExecute())
		throw Form::GradeTooLowException();
	this->action();
}

Form::AFormException::AFormException(void) {}
Form::AFormException::~AFormException(void) throw() {}
Form::AFormException &Form::AFormException::operator=(Form::AFormException const &rhs)
{
	(void)rhs;
	return *this;
}

Form::FormNotSignedException::FormNotSignedException(void) {}
Form::FormNotSignedException::~FormNotSignedException(void) throw() {}
char const *Form::FormNotSignedException::what() const throw() { return "Form not signed exception"; }
Form::FormNotSignedException &Form::FormNotSignedException::operator=(Form::FormNotSignedException const &rhs)
{
	(void)rhs;
	return *this;
}

Form::GradeTooLowException::GradeTooLowException(void) {}
Form::GradeTooLowException::~GradeTooLowException(void) throw() {}
char const *Form::GradeTooLowException::what() const throw() { return "Grade too low exception"; }
Form::GradeTooLowException &Form::GradeTooLowException::operator=(Form::GradeTooLowException const &rhs)
{
	(void)rhs;
	return *this;
}

Form::GradeTooHighException::GradeTooHighException(void) {}
Form::GradeTooHighException::~GradeTooHighException(void) throw() {}
char const *Form::GradeTooHighException::what() const throw() { return "Grade too high exception"; }
Form::GradeTooHighException &Form::GradeTooHighException::operator=(Form::GradeTooHighException const &rhs)
{
	(void)rhs;
	return *this;
}

Form::UnknownFormException::UnknownFormException(void) {}
Form::UnknownFormException::~UnknownFormException(void) throw() {}
char const *Form::UnknownFormException::what() const throw() { return "Unknown form exception"; }
Form::UnknownFormException &Form::UnknownFormException::operator=(Form::UnknownFormException const &rhs)
{
	(void)rhs;
	return *this;
}