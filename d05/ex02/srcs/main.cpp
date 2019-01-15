#include <iostream>
#include "BureaucratClass.hpp"
#include "FormClass.hpp"
#include "ShrubberyCreationFormClass.hpp"
#include "RobotomyRequestFormClass.hpp"
#include "PresidentialPardonFormClass.hpp"

int main()
{
	std::srand(time(NULL));
	try
	{
		ShrubberyCreationForm f("EkiEkiPaTong");
		RobotomyRequestForm r("Jack Nicholson");
		PresidentialPardonForm p("Christophe Dettinger");

		Bureaucrat peon("Gratte papier", 146);
		Bureaucrat fantassin("Middle Manager", 138);
		Bureaucrat general("Big boss", 4);

		std::cout << std::endl << std::endl;
		general.executeForm(f);
		std::cout << std::endl;
		general.signForm(f);
		std::cout << std::endl;
		fantassin.executeForm(f);
		std::cout << std::endl;
		general.executeForm(f);
		std::cout << std::endl << std::endl;
		general.signForm(r);
		std::cout << std::endl << std::endl;
		general.executeForm(r);
		std::cout << std::endl << std::endl;
		general.executeForm(r);
		std::cout << std::endl << std::endl;
		general.executeForm(r);
		std::cout << std::endl << std::endl;
		general.signForm(p);
		std::cout << std::endl << std::endl;
		general.executeForm(p);
	}
	catch (Form::AFormException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}