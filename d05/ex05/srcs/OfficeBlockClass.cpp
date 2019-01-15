#include "OfficeBlockClass.hpp"
#include <iostream>

OfficeBlock::OfficeBlock(void) :
_intern(new Intern()),
_signator(nullptr),
_executor(nullptr)
{
	return;
}

OfficeBlock::OfficeBlock(Intern &intern, Bureaucrat &signator, Bureaucrat &executor) :
_intern(&intern),
_signator(&signator),
_executor(&executor)
{
	return;
}

OfficeBlock::~OfficeBlock(void)
{
	return;
}

void OfficeBlock::doBureaucracy(std::string const formName, std::string const target) const
{
	if (nullptr == this->_intern || nullptr == this->_signator || nullptr == this->_executor)
		throw OfficeBlock::MissingTeamMemberException();
	try
	{
		Form	*form;
		form = this->_intern->makeForm(formName, target);
		this->_signator->signForm(*form);
		this->_executor->executeForm(*form);
	}
	catch (Form::AFormException &e)
	{
		std::cout << "Problem with form " << formName << ": " << e.what() << std::endl;
	}
}

void OfficeBlock::assignBureaucrat(Bureaucrat &bureaucrat)
{
	if (nullptr == this->_signator)
		this->setSigner(bureaucrat);
	else if (nullptr == this->_executor)
		this->setExecutor(bureaucrat);
	else
		throw OfficeBlock::TeamFullException();
}

void OfficeBlock::setIntern(Intern &intern) { this->_intern = &intern; }
void OfficeBlock::setSigner(Bureaucrat &signer) { this->_signator = &signer; }
void OfficeBlock::setExecutor(Bureaucrat &executor) { this->_executor = &executor; }

OfficeBlock::AOfficeBlockException::AOfficeBlockException(void) {}
OfficeBlock::AOfficeBlockException::~AOfficeBlockException(void) throw() {}

OfficeBlock::MissingTeamMemberException::MissingTeamMemberException(void) {}
OfficeBlock::MissingTeamMemberException::~MissingTeamMemberException(void) throw() {}
char const *OfficeBlock::MissingTeamMemberException::what() const throw() {
return "OfficeBlock lacks a team member";
}

OfficeBlock::TeamFullException::TeamFullException(void) {}
OfficeBlock::TeamFullException::~TeamFullException(void) throw() {}
char const *OfficeBlock::TeamFullException::what() const throw() { return "Team is full"; }