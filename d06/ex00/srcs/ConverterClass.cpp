#include "ConverterClass.hpp"
#include <iostream>
#include <string>
// #include <cstdlib>
#include <sstream>
#include <limits>

Converter::Converter(std::string input) :
_doubleRepresentation(Converter::_representAsDouble(input))
{
	return;
}

Converter::~Converter(void)
{
	return;
}

double			Converter::_representAsDouble(std::string s)
{
	// check if compiler has infinity and NaN ?!
	if (std::string::npos != s.find("+inf"))
		return (std::numeric_limits<double>::infinity());
	if (std::string::npos != s.find("-inf"))
		return (-std::numeric_limits<double>::infinity());
	if (std::string::npos != s.find("nanf"))
		return (-std::numeric_limits<double>::quiet_NaN());
	std::stringstream	stream(s);
	double				d;
	stream >> d;
	if (stream.failbit)
		return (-std::numeric_limits<double>::quiet_NaN());
	return d;


	// return (strtod(s.c_str(), nullptr));
}