#ifndef FIXEDCLASS_HPP
# define FIXEDCLASS_HPP

class Fixed {

public: 

	typedef Fixed	t;
	Fixed(void); 
	Fixed(Fixed const & src); 
	~Fixed(void); 

	Fixed &				operator=(Fixed const & rhs);
	int					getRawBits(void) const;
	void				setRawBits(int const raw);


private:

	static int const	_fractionalBits;
	int					_rawBits;


};


#endif