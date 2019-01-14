#include "TimeClass.hpp"
#include <iostream>

std::clock_t const	Time::_start = std::clock();
std::clock_t		Time::_last = std::clock();
float				Time::_sinceStart = 0.;
float				Time::_deltaTime = 0.;

Time::Time(void)
{
	Time::update();
	return;
}

Time::Time(Time const &src)
{
	Time::update();
	*this = src;
	return;
}

Time::~Time(void)
{
	return;
}

Time &	Time::operator=(Time const & rhs)
{
	std::cout << rhs << std::endl;
	return *this;
}

std::string const Time::toString(void) const
{
	return std::to_string(std::clock() - Time::_start) + " seconds since game began";
}

std::ostream &	operator<< (std::ostream & o, Time const & rhs)
{
	o << rhs.toString();
	return o;
}

float Time::deltaTime(void) { return Time::_deltaTime; }
float Time::sinceStart(void) { return Time::_sinceStart ; }
void Time::update(void)
{
	std::clock_t now = std::clock();
	Time::_deltaTime = (now - Time::_last) / (float) CLOCKS_PER_SEC;
	Time::_last = now;
	Time::_sinceStart = (now - Time::_start) / (float) CLOCKS_PER_SEC;
	return;
}

void Time::reinitDeltaTime(void)
{
	Time::_last = std::clock();
	Time::update();
}
