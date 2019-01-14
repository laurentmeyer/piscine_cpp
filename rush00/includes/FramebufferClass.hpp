#ifndef FRAMEBUFFERCLASS_HPP
# define FRAMEBUFFERCLASS_HPP

# include <iostream>
# include <curses.h>

class Framebuffer {

public: 

	Framebuffer(void); 
	~Framebuffer(void); 

	static void		init(int rows, int cols); 
	static void		clear(void); 
	static void		set(unsigned int i, chtype value); 
	static size_t	getSize(void);
	static chtype	getCurse(size_t i);


private:

	Framebuffer(Framebuffer const & src); 
	Framebuffer &		operator=(Framebuffer const & rhs);

	static chtype		*_buffer;
	static size_t		_size;


};

#endif