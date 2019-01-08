#include "HumanBClass.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	_weapon = nullptr;
	return;
}

HumanB::~HumanB(void)
{
	return;
}

void HumanB::setWeapon(Weapon &weapon) { this->_weapon = &weapon; }
void HumanB::attack(void) const
{
	std::cout << this->_name << "  attacks with his " << this->_weapon->getType() << std::endl;
}