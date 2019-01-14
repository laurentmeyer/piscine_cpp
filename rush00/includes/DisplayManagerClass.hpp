#ifndef DISPLAYMANAGERCLASS_HPP
# define DISPLAYMANAGERCLASS_HPP

# include <iostream>
# include <curses.h>
# include "FramebufferClass.hpp"

class DisplayManager {

public: 

	DisplayManager(void); 
	~DisplayManager(void); 

	static void		init(void);
	static void		destroy(void);
	static void		clear(void);
	static void		update(void);
	static void		pixelPut(size_t x, size_t y, chtype curse);
	static int		getRows(void);
	static int		getCols(void);
	static void		setQuitMsg(std::string message);
	static std::string	getQuitMsg(void);

private:
	DisplayManager(DisplayManager const & src); 
	DisplayManager &		operator=(DisplayManager const & rhs);

	static int			_rows;
	static int			_cols;
	static std::string	_quitMsg;
	static WINDOW		*_gameWindow;
	static WINDOW		*_scoreWindow;

};

#endif