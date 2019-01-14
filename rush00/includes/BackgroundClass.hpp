#ifndef BACKGROUNDCLASS_HPP
# define BACKGROUNDCLASS_HPP

# include <iostream>

class Background {

public: 
	static void			init(void);
	static void			display(void);
	static void			update(void);


private:
	Background(void); 
	Background(Background const & src); 
	~Background(void); 
	Background &		operator=(Background const & rhs);
	std::string const	toString(void) const;

	static size_t			*_height;
	static float			_lastMove;
	static float const		_secondsPerMove;

};


#endif