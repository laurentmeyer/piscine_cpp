#include "PonyClass.hpp"
#include <iostream>

Pony::Pony(void) : _noise("Hi Han") {
	this->_legs = 4;
	std::cout << this->_noise << "! Pony with " << std::to_string(this->_legs) << " legs is born" <<  std::endl;
	return;
}

Pony::Pony(std::string noise) : _noise(noise) {
	this->_legs = 4;
	std::cout << this->_noise << "! Pony with " << std::to_string(this->_legs) << " legs is born" <<  std::endl;
	return;
}

Pony::~Pony(void) {
	std::cout << "Pony with " << std::to_string(this->_legs) << " legs is dead. " << this->_noise << " :(" << std::endl;
	return;
}

int		Pony::getLegs (void) const { return (this->_legs); }
void	Pony::setLegs (int legs) { this->_legs = legs; }