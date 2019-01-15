#include "CentralBureaucracyClass.hpp"
#include <iostream>

size_t const		CentralBureaucracy::_blocksCount = 20;
size_t const		CentralBureaucracy::_bureaucratQueueMaxSize = 32;
size_t const		CentralBureaucracy::_targetQueueMaxSize = 32;
size_t 				CentralBureaucracy::_targetQueueCount = 0;
std::string const	CentralBureaucracy::_someRandomNames[] = {"MONSIEUR Macron", "Dodo la saumure", "Pénélope FIllon", "Sasha Grey"};

CentralBureaucracy::CentralBureaucracy(void)
{
	this->_officeBlocks = new OfficeBlock[CentralBureaucracy::_blocksCount];
	this->_bureaucratQueue = new Bureaucrat*[CentralBureaucracy::_bureaucratQueueMaxSize];
	this->_targetQueue = new std::string[CentralBureaucracy::_targetQueueMaxSize];
	return;
}

CentralBureaucracy::~CentralBureaucracy(void)
{
	delete [] this->_officeBlocks;
	delete [] this->_bureaucratQueue;
	delete [] this->_targetQueue;
	return;
}

std::string const CentralBureaucracy::toString(void) const
{
	return "CentralBureaucracy";
}

std::ostream &	operator<< (std::ostream & o, CentralBureaucracy const & rhs)
{
	o << rhs.toString();
	return o;
}

void			CentralBureaucracy::generateRandomTargets(size_t targetNumber)
{
	const size_t	count = sizeof(CentralBureaucracy::_someRandomNames) / sizeof(CentralBureaucracy::_someRandomNames[0]);

	for(size_t i = 0; i < targetNumber; i++)
		this->queueUp(CentralBureaucracy::_someRandomNames[std::rand() % count]);
}

void CentralBureaucracy::queueUp(std::string target)
{
	if (CentralBureaucracy::_targetQueueCount >= CentralBureaucracy::_targetQueueMaxSize)
		throw CentralBureaucracy::TargetQueueFullException();
	CentralBureaucracy::_targetQueue[CentralBureaucracy::_targetQueueCount] = target;
	CentralBureaucracy::_targetQueueCount++;
}

void CentralBureaucracy::feedBureaucrat(Bureaucrat &bureaucrat)
{
	static size_t currentAvailableOffice = 0;

	try
	{
		this->_officeBlocks[currentAvailableOffice].assignBureaucrat(bureaucrat);
	}
	catch (OfficeBlock::TeamFullException &e)
	{
		(void)e;
		currentAvailableOffice++;
		if (currentAvailableOffice >= CentralBureaucracy::_blocksCount)
			throw CentralBureaucracy::AllOfficesFullException();
	}
}

void CentralBureaucracy::doBureaucracy(void)
{
	size_t currentOffice = 0;
	size_t t = 0;
	std::string const	forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	while (t < CentralBureaucracy::_targetQueueCount)
	{
		if (currentOffice >= CentralBureaucracy::_blocksCount)
		{
			currentOffice = 0;
		}
		try
		{
			CentralBureaucracy::_officeBlocks[currentOffice].doBureaucracy(forms[std::rand() % 3], CentralBureaucracy::_targetQueue[t]);
			currentOffice++;
			t++;
		}
		catch (OfficeBlock::AOfficeBlockException &e)
		{
			std::cout << e.what() << std::endl;
			currentOffice++;
		}
	}
}

CentralBureaucracy::ACentralBureaucracyException::ACentralBureaucracyException(void) {}
CentralBureaucracy::ACentralBureaucracyException::~ACentralBureaucracyException(void) throw() {}

CentralBureaucracy::AllOfficesFullException::AllOfficesFullException(void) {}
CentralBureaucracy::AllOfficesFullException::~AllOfficesFullException(void) throw() {}
char const *CentralBureaucracy::AllOfficesFullException::what() const throw() { return "All offices are full"; }

CentralBureaucracy::TargetQueueFullException::TargetQueueFullException(void) {}
CentralBureaucracy::TargetQueueFullException::~TargetQueueFullException(void) throw() {}
char const *CentralBureaucracy::TargetQueueFullException::what() const throw() { return "Target queue is full"; }

CentralBureaucracy::BureaucratQueueFullException::BureaucratQueueFullException(void) {}
CentralBureaucracy::BureaucratQueueFullException::~BureaucratQueueFullException(void) throw() {}
char const *CentralBureaucracy::BureaucratQueueFullException::what() const throw() { return "Target queue is full"; }