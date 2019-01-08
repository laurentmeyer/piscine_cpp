#include "BrainClass.hpp"
#include <iostream>
#include <sstream>

Brain::Brain(void)
{
	// std::cout << "brain created " << this->identify() << std::endl;
	return;
}

Brain::~Brain(void) {
	return;
}

std::string		Brain::identify(void) const
{
	std::ostringstream	buffer;

	buffer << std::hex << this;
	return buffer.str();
}