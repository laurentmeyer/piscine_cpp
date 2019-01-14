#ifndef INPUTMANAGERCLASS_HPP
# define INPUTMANAGERCLASS_HPP

# include <iostream>
# include <curses.h>

class InputManager {

public: 

	InputManager(void); 
	~InputManager(void); 

	static void			update(void);
	static bool			getKeyStatus(char key);

private:
	InputManager(InputManager const & src); 
	InputManager &		operator=(InputManager const & rhs);
	std::string const	toString(void) const;

	static bool			_pressedKeys[127];

};

#endif