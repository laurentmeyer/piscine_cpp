#include "InputManagerClass.hpp"
#include "GameManagerClass.hpp"
#include <iostream>

bool		InputManager::_pressedKeys[127] = {false};

InputManager::InputManager(void)
{
	return;
}

InputManager::~InputManager(void)
{
	return;
}

void		InputManager::update(void)
{
	int			ch = getch();

	for (int i = 0; i < 127; i++)
		InputManager::_pressedKeys[i] = (i == ch);
	if (InputManager::getKeyStatus('q'))
		GameManager::quit("Bye Bye!");
}

bool			InputManager::getKeyStatus(char key)
{
	return InputManager::_pressedKeys[(size_t)key] ;
}
