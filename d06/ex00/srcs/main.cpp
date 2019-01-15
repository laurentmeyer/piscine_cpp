#include <iostream>
#include "ConverterClass.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert [string]" << std::endl;
		return (0);
	}
	Converter converter(av[1]);
	std::cout << static_cast<int>(converter) << std::endl;
	return 0;
}