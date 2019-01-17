#include <iostream>
#include "ArrayClass.hpp"

template <typename T>
void	print_endline(T & a)
{
	std::cout << a << std::endl;
}

int main(void)
{
	try
	{
		Array<std::string> strArray(4);
		strArray[0] = "Salut";
		strArray[1] = "tu";
		strArray[2] = "vas";
		strArray[3] = "bien ?";
		std::cout << "size = " << strArray.size() << std::endl;
		for (size_t i = 0; i < strArray.size() + 1; i++)
			print_endline(strArray[i]);
	}
	catch (std::exception &se)
	{
		std::cout << se.what() << std::endl;
	}
	try
	{
		Array<double> doubleArray(2);
		doubleArray[0] = 420.024;
		doubleArray[1] = -420.024;
		doubleArray[2] = 42;

	}
	catch (std::exception &se)
	{
		std::cout << se.what() << std::endl;
	}
	try
	{
		Array<double> doubleArray(2);
		doubleArray[0] = 420.024;
		doubleArray[1] = -420.024;
		Array<double> tripleArray(5);
		std::cout << "size = " << tripleArray.size() << std::endl;
		tripleArray = doubleArray;
		std::cout << "size = " << tripleArray.size() << std::endl;
		for (size_t i = 0; i < tripleArray.size(); i++)
			print_endline(tripleArray[i]);
	}
	catch (std::exception &se)
	{
		std::cout << se.what() << std::endl;
	}
}