#include "WeaponClass.hpp"

Weapon::Weapon(std::string type) : _type(type) {
	return;
}

Weapon::~Weapon(void) {
	return;
}

std::string const	&Weapon::getType (void) const { return (this->_type); }
void				Weapon::setType (std::string type) { this->_type = type; }