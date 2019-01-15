#ifndef CONVERTERCLASS_HPP
# define CONVERTERCLASS_HPP

# include <iostream>
# include <string>


class Converter
{

  public:
	Converter(std::string input);
	~Converter(void);

	operator int() { return static_cast<int>(this->_doubleRepresentation); }
	operator char()
	{
		if (std::)

		return static_cast<int>(this->_doubleRepresentation);
	}

  private:
	Converter(void);
	Converter(Converter const &src);
	Converter &operator=(Converter const &rhs);

	static double _representAsDouble(std::string s);

	// bool const		_isNan;
	// bool const		_isDisplayableAsChar;
	// bool const		_isInfinity;
	double const _doubleRepresentation;
};

#endif