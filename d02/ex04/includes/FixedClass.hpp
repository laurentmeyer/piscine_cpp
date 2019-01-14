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

	Fixed &				operator= (Fixed const & rhs);
	bool				operator> (Fixed const & rhs) const;
	bool				operator>= (Fixed const & rhs) const;
	bool				operator< (Fixed const & rhs) const;
	bool				operator<= (Fixed const & rhs) const;
	bool				operator== (Fixed const & rhs) const;
	bool				operator!= (Fixed const & rhs) const;
	Fixed &				operator+ (Fixed const & rhs);
	Fixed &				operator- (Fixed const & rhs);
	Fixed &				operator* (Fixed const & rhs);
	Fixed &				operator/ (Fixed const & rhs);
	Fixed &				operator++ (void);
	Fixed				operator++ (int);
	Fixed &				operator-- (void);
	Fixed				operator-- (int);
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	int					toInt(void) const;
	float				toFloat(void) const;
	std::string const	toString(void) const;

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);

  private:
	static int const _fractionalBits;
	int _rawBits;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif