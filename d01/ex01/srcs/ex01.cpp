#include <iostream>

void memoryLeak() {
	std::string*	panthere = new std::string("String panthere");

	std::cout << *panthere << std::endl;
	delete panthere;
}

int	main(void)
{
	memoryLeak();
	memoryLeak();
	memoryLeak();
	memoryLeak();
	while (42)
		;
	return (0);
}