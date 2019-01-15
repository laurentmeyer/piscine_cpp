#include <iostream>
#include "BureaucratClass.hpp"
#include "FormClass.hpp"
#include "InternClass.hpp"
#include "OfficeBlockClass.hpp"
#include "ShrubberyCreationFormClass.hpp"
#include "RobotomyRequestFormClass.hpp"
#include "PresidentialPardonFormClass.hpp"
#include "CentralBureaucracyClass.hpp"

int main()
{
	std::srand(time(NULL));
	size_t bCount = 20;
	size_t tCount = 32;

	try
	{
		CentralBureaucracy bigCorp;
		Bureaucrat slaves[bCount];
		for (size_t i = 0; i < bCount; i++)
			bigCorp.feedBureaucrat(slaves[i]);
		bigCorp.generateRandomTargets(tCount);
		bigCorp.doBureaucracy();
	}
	catch (CentralBureaucracy::ACentralBureaucracyException &e)
	{
		std::cout << e.what() << std::endl;
	}
}