#include "HumanClass.hpp"

Human::Human(void) {
	return;
}

Human::~Human(void) {
	return;
}

Brain	&Human::getBrain (void) { return (this->_brain); }

std::string		Human::identify(void) const {
	return this->_brain.identify();
}