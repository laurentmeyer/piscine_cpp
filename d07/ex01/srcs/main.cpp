#include <iostream>

template <typename T, typename U>
void	iter(T array[], size_t len, U (*f)(T&))
{
	for (size_t i = 0; i < len; i++)
		(*f)(array[i]);
}

template <typename T>
void	print_endline(T & a)
{
	std::cout << a << std::endl;
}

int main(void)
{
	int intArray[] = {5, 4, 3, 2, 1};
	::iter<int, void>(intArray, sizeof(intArray) / sizeof(intArray[0]), &::print_endline<int>);

	std::string strArray[] = { "coucou", "bouzin", "goodbye", "yesterday"};
	::iter<std::string, void>(strArray, sizeof(strArray) / sizeof(strArray[0]), &::print_endline<std::string>);
}