#include "AFormClass.hpp"
#include <iostream>
#include <sstream>

AForm::AForm(std::string const name, unsigned int minSignature, unsigned int minExecution) :
_minGradeExecute(minExecution),
_minGradeSign(minSignature),
_name(name)
{
	if (this->_minGradeSign > Bureaucrat::getMinGrade() || this->_minGradeExecute > Bureaucrat::getMinGrade())
		throw AForm::GradeTooLowException();
	if (this->_minGradeSign < Bureaucrat::getMaxGrade() || this->_minGradeExecute < Bureaucrat::getMaxGrade())
		throw AForm::GradeTooHighException();
	this->_setSigned(false);
	return;
}

AForm::AForm(AForm const &src) :
_minGradeExecute(src.getMinGradeExecute()),
_minGradeSign(src.getMinGradeSign())
{
	if (this->_minGradeSign > Bureaucrat::getMinGrade() || this->_minGradeExecute > Bureaucrat::getMinGrade())
		throw AForm::GradeTooLowException();
	if (this->_minGradeSign < Bureaucrat::getMaxGrade() || this->_minGradeExecute < Bureaucrat::getMaxGrade())
		throw AForm::GradeTooHighException();
	this->_setSigned(src.getSigned());
	*this = src;
	return;
}

AForm::~AForm(void)
{
	return;
}

AForm &AForm::operator=(AForm const &rhs)
{
	(void)rhs;
	return *this;
}

std::string const AForm::toString(void) const
{
	std::ostringstream s;

	s << (this->_signed ? "signed" : "unsigned") << " form " << this->getName()
		<< ", grade " << this->getMinGradeSign() << " to sign"
		<< ", grade " << this->getMinGradeExecute() << " to execute";
	return s.str();
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs)
{
	o << rhs.toString();
	return o;
}

bool AForm::getSigned(void) const { return (this->_signed); }
unsigned int AForm::getMinGradeSign(void) const { return (this->_minGradeSign); }
unsigned int AForm::getMinGradeExecute(void) const { return (this->_minGradeExecute); }
std::string const	AForm::getName (void) const { return (this->_name); }

void AForm::_setSigned(bool s) { this->_signed = s; }

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->getMinGradeSign())
		throw AForm::GradeTooLowException();
	this->_setSigned(true);
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getMinGradeExecute())
		throw AForm::GradeTooLowException();
	this->action();
}

AForm::FormNotSignedException::FormNotSignedException(void) {}
AForm::FormNotSignedException::~FormNotSignedException(void) throw() {}
char const *AForm::FormNotSignedException::what() const throw() { return "Form not signed exception"; }
AForm::FormNotSignedException &AForm::FormNotSignedException::operator=(AForm::FormNotSignedException const &rhs)
{
	(void)rhs;
	return *this;
}

AForm::GradeTooLowException::GradeTooLowException(void) {}
AForm::GradeTooLowException::~GradeTooLowException(void) throw() {}
char const *AForm::GradeTooLowException::what() const throw() { return "Grade too low exception"; }
AForm::GradeTooLowException &AForm::GradeTooLowException::operator=(AForm::GradeTooLowException const &rhs)
{
	(void)rhs;
	return *this;
}

AForm::GradeTooHighException::GradeTooHighException(void) {}
AForm::GradeTooHighException::~GradeTooHighException(void) throw() {}
char const *AForm::GradeTooHighException::what() const throw() { return "Grade too high exception"; }
AForm::GradeTooHighException &AForm::GradeTooHighException::operator=(AForm::GradeTooHighException const &rhs)
{
	(void)rhs;
	return *this;
}