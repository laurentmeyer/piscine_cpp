#ifndef TIMECLASS_HPP
# define TIMECLASS_HPP

# include <iostream>
# include <ctime>

class Time {

public: 

	Time(void); 
	~Time(void); 

	std::string const	toString(void) const;
	static float		deltaTime(void);
	static float 		sinceStart(void);
	static void			update(void);
	static void			reinitDeltaTime(void);


private:

	Time(Time const & src); 
	static std::clock_t const	_start;
	static std::clock_t 		_last;
	static float 				_deltaTime;
	static float 				_sinceStart;

	Time &		operator=(Time const & rhs);

};

std::ostream &	operator<< (std::ostream & o, Time const & rhs);

#endif