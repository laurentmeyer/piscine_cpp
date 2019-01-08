#include "ReplaceClass.hpp"

Replace::Replace(std::string const s1, std::string const s2) : _s1(s1), _s2(s2) {
	return;
}

Replace::Replace(void) {
	return;
}

Replace::~Replace(void) {
	return;
}

std::string const	Replace::replace(std::string const line)
{
	size_t 		p;
	size_t 		last = 0;
	std::string	acc = "";

	while (std::string::npos != (p = line.find(this->_s1, last)))
	{
		acc += line.substr(last, p - last) + this->_s2;
		last += this->_s1.length();
	}
	acc += line.substr(last, line.length() - last);
	return acc;
}