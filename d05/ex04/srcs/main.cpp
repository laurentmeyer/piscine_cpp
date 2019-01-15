#include <iostream>
#include "BureaucratClass.hpp"
#include "FormClass.hpp"
#include "InternClass.hpp"
#include "OfficeBlockClass.hpp"
#include "ShrubberyCreationFormClass.hpp"
#include "RobotomyRequestFormClass.hpp"
#include "PresidentialPardonFormClass.hpp"

int main()
{
	std::srand(time(NULL));

	Intern idiotOne;
	Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
	// Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
	Bureaucrat bob = Bureaucrat("Bobby Bobson", 2);
	OfficeBlock ob;
	ob.setIntern(idiotOne);
	ob.setSigner(bob);
	ob.setExecutor(hermes);
	try
	{
		ob.doBureaucracy("robotomy request", "Zobi la mouche");
		// ob.doBureaucracy("mutant pig termination", "Pigley");
	}
	catch (OfficeBlock::AOfficeBlockException &e)
	{
		std::cout << e.what() << std::endl;
		/* specific known error happens, say something */
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		/* oh god, unknown error, what to do ?! */
	}
}