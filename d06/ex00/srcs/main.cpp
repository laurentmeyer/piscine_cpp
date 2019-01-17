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
	std::cout << "char: " << converter.toCharString() << std::endl;
	std::cout << "int: " << converter.toIntString() << std::endl;
	std::cout << "float: " << converter.toFloatString() << std::endl;
	std::cout << "double: " << converter.toDoubleString() << std::endl;
	return 0;
}