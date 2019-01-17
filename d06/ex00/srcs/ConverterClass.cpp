#include "ConverterClass.hpp"
#include <iostream>
#include <string>
// #include <cstdlib>
#include <sstream>
#include <limits>
#include <climits>
#include <cctype>
#include <iomanip>

Converter::Converter(std::string input)
{
	this->_isNan = false;
	this->_charOverflow = false;
	this->_charUnderflow = false;
	this->_intOverflow = false;
	this->_intUnderflow = false;
	this->_convert(input);
	return;
}

Converter::~Converter(void)
{
	return;
}

void		Converter::_convert(std::string s)
{
	if (s.length() == 1 && (s.c_str()[0] < '0' ||  s.c_str()[0] > '9'))
	{
		this->_fillChar(s.c_str()[0]);
		return ;
	}
	size_t	firstDigit = s.find_first_of("0123456789");
	if (std::string::npos != firstDigit)
	{
		std::string sign = "";
		if (firstDigit > 0 && (s.at(firstDigit - 1) == '+' || s.at(firstDigit - 1) == '-'))
			sign = s.substr(firstDigit - 1, 1);
		if (s.find_first_not_of(" \t0123456789+-") < firstDigit)
		{
			this->_fillNan();
			return ;
		}
		size_t	afterLastDigit = s.find_first_not_of("0123456789 \t", firstDigit);
		if (std::string::npos == afterLastDigit)
		{
			std::string	str = s.substr(firstDigit);
			this->_fillInt(sign + str);
			return ;
		}
		if (s.at(afterLastDigit) == 'f' && s.length() == afterLastDigit + 1)
		{
			this->_fillFloat(sign + s.substr(firstDigit, afterLastDigit - firstDigit));
			return ;
		}
		if (s.at(afterLastDigit) == '.')
		{
			size_t	afterFinalDigit = s.find_first_not_of("0123456789", afterLastDigit + 1);
			if (std::string::npos == afterFinalDigit)
			{
				this->_fillDouble(sign + s.substr(firstDigit));
				return;
			}
			if (s.at(afterFinalDigit) == 'f' && s.length() == afterFinalDigit + 1)
			{
				this->_fillFloat(sign + s.substr(firstDigit, afterFinalDigit - firstDigit));
				return;
			}
		}
	}
	if ((std::string::npos != s.find("+inf") && s.length() == 4)
		|| (std::string::npos != s.find("+inff") && s.length() == 5))
	{
		this->_fillPositiveInfinity(s.length() == 4);
		return ;
	}
	if ((std::string::npos != s.find("-inf") && s.length() == 4)
		|| (std::string::npos != s.find("-inff") && s.length() == 5))
	{
		this->_fillNegativeInfinity(s.length() == 4);
		return ;
	}
	this->_fillNan();
	return;
}

void Converter::_fillNan(void)
{
	this->_type = E_NAN;
	this->_isNan = true;
	this->_doubleRepresentation = std::numeric_limits<double>::quiet_NaN();
	this->_floatRepresentation = std::numeric_limits<float>::quiet_NaN();
}

void Converter::_fillPositiveInfinity(bool isFloat)
{
	this->_type = isFloat ? E_FLOAT : E_DOUBLE;
	this->_charOverflow = true;
	this->_intOverflow = true;
	this->_doubleRepresentation = std::numeric_limits<double>::infinity();
	this->_floatRepresentation = std::numeric_limits<float>::infinity();
}

void Converter::_fillNegativeInfinity(bool isFloat)
{
	this->_type = isFloat ? E_FLOAT : E_DOUBLE;
	this->_charUnderflow = true;
	this->_intUnderflow = true;
	this->_doubleRepresentation = -std::numeric_limits<double>::infinity();
	this->_floatRepresentation = -std::numeric_limits<float>::infinity();
}

void Converter::_fillChar(char c)
{
	this->_type = E_CHAR;
	this->_charRepresentation = c;
	this->_intRepresentation = static_cast<int>(this->_charRepresentation);
	this->_floatRepresentation = static_cast<float>(this->_charRepresentation);
	this->_doubleRepresentation = static_cast<double>(this->_charRepresentation);
}

void Converter::_fillInt(std::string s)
{
	this->_type = E_INT;

	double d = strtod(s.c_str(), nullptr);
	this->_intOverflow = (d > static_cast<double>(INT_MAX));
	this->_intUnderflow = (d < static_cast<double>(INT_MIN));
	this->_intRepresentation = static_cast<int>(d);

	this->_charOverflow = (d > static_cast<double>(CHAR_MAX));
	this->_charUnderflow = (d < static_cast<double>(CHAR_MIN));
	this->_charRepresentation = static_cast<char>(this->_intRepresentation);

	this->_floatRepresentation = static_cast<float>(this->_intRepresentation);
	this->_doubleRepresentation = static_cast<double>(this->_intRepresentation);
}

void Converter::_fillFloat(std::string s)
{
	this->_type = E_FLOAT;
	this->_floatRepresentation = strtof(s.c_str(), nullptr);

	this->_charOverflow = (this->_floatRepresentation > static_cast<float>(CHAR_MAX));
	this->_charUnderflow = (this->_floatRepresentation < static_cast<float>(CHAR_MIN));
	this->_charRepresentation = static_cast<char>(this->_floatRepresentation);

	this->_intOverflow = (this->_floatRepresentation > static_cast<float>(INT_MAX));
	this->_intUnderflow = (this->_floatRepresentation < static_cast<float>(INT_MIN));
	this->_intRepresentation = static_cast<int>(this->_floatRepresentation);

	this->_doubleRepresentation = static_cast<double>(this->_floatRepresentation);
}

void Converter::_fillDouble(std::string s)
{
	this->_type = E_DOUBLE;
	this->_doubleRepresentation = strtod(s.c_str(), nullptr);

	this->_charOverflow = (this->_doubleRepresentation > static_cast<double>(CHAR_MAX));
	this->_charUnderflow = (this->_doubleRepresentation < static_cast<double>(CHAR_MIN));
	this->_charRepresentation = static_cast<char>(this->_doubleRepresentation);

	this->_intOverflow = (this->_doubleRepresentation > static_cast<double>(INT_MAX));
	this->_intUnderflow = (this->_doubleRepresentation < static_cast<double>(INT_MIN));
	this->_intRepresentation = static_cast<int>(this->_doubleRepresentation);

	this->_floatRepresentation = static_cast<float>(this->_doubleRepresentation);
}

std::string Converter::toCharString(void)
{
	if (this->_isNan)
		return "impossible";
	if (this->_charOverflow == true)
		return "Overflow";
	if (this->_charUnderflow)
		return "Underflow";
	if (false == isprint(this->_charRepresentation))
		return "Non displayable";
	const char s[] = {this->_charRepresentation, '\0'};
	return std::string(s);
}

std::string Converter::toIntString(void)
{
	if (this->_isNan)
		return "impossible";
	if (this->_intOverflow)
		return "Overflow";
	if (this->_intUnderflow)
		return "Underflow";
	return std::to_string(this->_intRepresentation);
}

std::string Converter::toFloatString(void)
{
	std::stringstream stream;
	stream << std::fixed << std::setprecision(1) << this->_floatRepresentation << "f";
	return stream.str();
}

std::string Converter::toDoubleString(void)
{
	std::stringstream stream;
	stream << std::fixed << std::setprecision(1) << this->_doubleRepresentation;
	return stream.str();
}

// double Converter::_representAsDouble(std::string s)
// {
// 	if (std::string::npos != s.find("+inf"))
// 	{
// 		this->_isPositiveInfinity = true;
// 		return (std::numeric_limits<double>::infinity());
// 	}
// 	if (std::string::npos != s.find("-inf"))
// 	{
// 		this->_isNegativeInfinity = true;
// 		return (-std::numeric_limits<double>::infinity());
// 	}
// 	if (std::string::npos != s.find("nan"))
// 	{
// 		this->_isNan = true;
// 		return (std::numeric_limits<double>::quiet_NaN());
// 	}
// 	size_t pos = s.find_first_not_of("0123456789.+-");
// 	std::stringstream stream(s.substr(0, pos));
// 	double d;
// 	stream >> d;
// 	if (stream.fail())
// 	{
// 		this->_isNan = true;
// 		return (std::numeric_limits<double>::quiet_NaN());
// 	}
// 	return d;
// }