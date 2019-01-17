#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator		easyfind(T & haystack, int needle)
{
	return std::find(haystack.begin(), haystack.end(), needle);
}

#endif // EASYFIND_HPP