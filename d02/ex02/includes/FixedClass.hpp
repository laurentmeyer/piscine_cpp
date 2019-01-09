#ifndef FIXEDCLASS_HPP
# define FIXEDCLASS_HPP

# include <iostream>

class Fixed {

public: 

	typedef Fixed	t;
	Fixed(void); 
	Fixed(int const i); 
	Fixed(float const f); 
	Fixed(Fixed const & src); 
	~Fixed(void); 

	Fixed &				operator=(Fixed const & rhs);
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	int					toInt(void) const;
	float				toFloat(void) const;


private:

	static int const	_fractionalBits;
	int					_rawBits;


};

std::ostream &	operator<< (std::ostream & o, Fixed const & rhs);


#endif