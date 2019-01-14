#include <iostream>
#include "BureaucratClass.hpp"
#include "FormClass.hpp"

int main()
{
	try
	{
		Form f("Dummy", 12, 12);
		// Form f("Dummy", 0, 12);
		// Form f("Dummy", 1, 12);
		// Form f("Dummy", 150, 12);
		// Form f("Dummy", 151, 12);
		Bureaucrat b("Gratte papier", 14);
		Bureaucrat c("Big boss", 4);

		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
		c.signForm(f);
		std::cout << f << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}