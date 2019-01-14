#include <iostream>
#include "BureaucratClass.hpp"

int main()
{
	Bureaucrat *test = nullptr;

	// test = new Bureaucrat("Big Boss", 0);
	try
	{
		// test = new Bureaucrat("Big Boss", 0);

		// Bureaucrat almostPeon("Zog Zog", 148);
		// for (size_t i = 0; i < 3; i++)
		// 	almostPeon.retrograde();

		Bureaucrat almostBoss("Nicolas Sadirac", 3);
		for (size_t i = 0; i < 3; i++)
			almostBoss.promote();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	test = nullptr;
	// while (1)
	// ;
	return 0;
}