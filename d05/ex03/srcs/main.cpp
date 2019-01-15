#include <iostream>
#include "BureaucratClass.hpp"
#include "FormClass.hpp"
#include "InternClass.hpp"
#include "ShrubberyCreationFormClass.hpp"
#include "RobotomyRequestFormClass.hpp"
#include "PresidentialPardonFormClass.hpp"

int main()
{
	std::srand(time(NULL));
	try
	{
		Intern someRandomIntern;
		Bureaucrat general("Big boss", 4);
		Form *rrf;

		std::cout << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		general.signForm(*rrf);
		general.executeForm(*rrf);
		general.executeForm(*rrf);
		general.executeForm(*rrf);
		delete rrf;

		std::cout << std::endl;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Gallahad");
		general.signForm(*rrf);
		general.executeForm(*rrf);
		delete rrf;

		std::cout << std::endl;
		rrf = someRandomIntern.makeForm("presidential pardon", "Marvin");
		general.signForm(*rrf);
		general.executeForm(*rrf);
		delete rrf;

		std::cout << std::endl;
		rrf = someRandomIntern.makeForm("underwater coloscopy", "Jul");
		general.signForm(*rrf);
		general.executeForm(*rrf);
		delete rrf;
	}
	catch (Form::AFormException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}