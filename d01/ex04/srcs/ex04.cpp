#include <iostream>

int main(void)
{
	std::string		hi = "HI THIS IS BRAIN";
	std::string		*hiPtr = &hi;
	std::string		&hiRef = hi;

	std::cout << "Displaying with pointer:   " << *hiPtr << std::endl;
	std::cout << "Displaying with reference: " << hiRef << std::endl;

	return (0);
}