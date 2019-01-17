#ifndef CONVERTERCLASS_HPP
# define CONVERTERCLASS_HPP

# include <iostream>
# include <string>


class Converter
{
	enum e_types { E_CHAR, E_INT, E_FLOAT, E_DOUBLE, E_NAN };

  public:
	Converter(std::string input);
	~Converter(void);

	std::string		toCharString(void);
	std::string		toIntString(void);
	std::string		toFloatString(void);
	std::string		toDoubleString(void);

  private:
	Converter(void);
	Converter(Converter const &src);
	Converter &operator=(Converter const &rhs);

	void					_convert(std::string s);
	void					_fillNan(void);
	void					_fillPositiveInfinity(bool isFloat);
	void					_fillNegativeInfinity(bool isFloat);
	void					_fillChar(char c);
	void					_fillInt(std::string s);
	void					_fillFloat(std::string s);
	void					_fillDouble(std::string s);

	Converter::e_types		_type;
	bool 					_isNan;
	// bool 					_isPositiveInfinity;
	// bool 					_isNegativeInfinity;
	char					_charRepresentation;
	int						_intRepresentation;
	float					_floatRepresentation;
	double					_doubleRepresentation;
	bool					_intOverflow;
	bool					_intUnderflow;
	bool					_charOverflow;
	bool					_charUnderflow;
};

#endif