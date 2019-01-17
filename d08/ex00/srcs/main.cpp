#include <iostream>
#include "easyfind.hpp"
#include <vector>

void	printInt(int i)
{
	std::cout << i << std::endl;
}

int main(void)
{
	std::vector<int> v;
	v.push_back(4);
	v.push_back(42);
	v.push_back(420);
	std::for_each(v.begin(), v.end(), &printInt);
	std::vector<int>::iterator i = easyfind< std::vector<int> >(v, 420);
	// std::vector<int>::iterator i = easyfind< std::vector<int> >(v, 4200);
	if (i != v.end())
		std::cout << "found i: " << *i << std::endl;
	else
		std::cout << "cannot find i" << std::endl;
	return 0;
}