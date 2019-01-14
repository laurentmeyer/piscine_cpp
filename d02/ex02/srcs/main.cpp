#include <iostream>
#include "FixedClass.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << "<== end of assignment tests ==>" << std::endl;

	Fixed const c(Fixed(3.33f) / Fixed(2));
	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << c << std::endl;

	Fixed d = c;
	std::cout << (int)(d == c) << std::endl;
	std::cout << (int)(d != c) << std::endl;
	std::cout << (int)(d >= c) << std::endl;
	std::cout << (int)(--d >= c) << std::endl;

	return 0;
}