#include "FieldClass.hpp"

Field::Field(void)
{
	return;
}

Field::Field(std::string name) : _name(name)
{
	return;
}

Field::~Field(void)
{
	return;
}

std::string Field::getName(void) const { return (this->_name); }
void 		Field::setName(std::string name) { this->_name = name; }
std::string Field::getValue(void) const { return (this->_value); }
int 		Field::setValue(void)
{
	std::string input;

	std::cout << "Enter " << this->_name << ": " << std::endl;
	std::getline(std::cin, input);
	if (std::cin.fail())
		return (0);
	this->_value = input;
	return (1);
}
std::string Field::toString(void) {
	return (this->_name + ": " + this->_value);
}