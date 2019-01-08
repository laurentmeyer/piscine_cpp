#include <iostream>
#include "BrainClass.hpp"
#include "HumanClass.hpp"

int main()
{
	Human bob;
	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
}