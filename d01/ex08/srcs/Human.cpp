#include "Human.hpp"
#include <iostream>

Human::funptr const		Human::_actions[] = {Human::rangedAttack};
std::string 			Human::_actionNames[] = {"rangedAttack"};

Human::Human(void)
{
	return ;
}

void Human::meleeAttack(std::string const &target) { std::cout << "Melee ATTACK on " << target << std::endl; }
void Human::rangedAttack(std::string const &target) { std::cout << "Ranged ATTACK on " << target << std::endl; }
void Human::intimidatingShout(std::string const &target) { std::cout << "Intimidating **shout** on " << target << std::endl; }
void Human::action(std::string const &action_name, std::string const &target) {
	int size = sizeof(Human::_actions) / sizeof(Human::_actions[0]);
	for (int i = 0; i < size; i++)
		if (action_name == _actionNames[i])
		{
			*(this->_actions[i])(target);
			return ;
		}
	std::cout << "Action " << action_name << " does not exist" << std::endl;
}