#include "FixedClass.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _rawBits(0)
{
	// std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(float const f)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_rawBits = (int)roundf(f * (1 << Fixed::_fractionalBits));
	return;
}

Fixed::Fixed(int const i)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_rawBits = (i << Fixed::_fractionalBits);
	return;
}

Fixed::Fixed(Fixed const &src)
{
	this->_rawBits = src.getRawBits();
	return;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
	return;
}

int Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw) { this->_rawBits = raw; }

Fixed &Fixed::operator=(Fixed const &rhs)
{
	// std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = rhs.getRawBits();
	return *this;
}

bool Fixed::operator>(Fixed const &rhs) const
{
	return this->_rawBits > rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return this->_rawBits >= rhs.getRawBits();
}

bool Fixed::operator<(Fixed const &rhs) const
{
	return this->_rawBits < rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	return this->_rawBits <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const &rhs) const
{
	return this->_rawBits == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	return this->_rawBits != rhs.getRawBits();
}

Fixed &	Fixed::operator+(Fixed const &rhs)
{
	Fixed	*ret = new Fixed();

	ret->setRawBits(this->getRawBits() + rhs.getRawBits());
	return *ret;
}

Fixed &	Fixed::operator-(Fixed const &rhs)
{
	Fixed	*ret = new Fixed();

	ret->setRawBits(this->getRawBits() - rhs.getRawBits());
	return *ret;
}

Fixed &	Fixed::operator*(Fixed const &rhs)
{
	Fixed		*ret = new Fixed();
	long long	mul;

	mul = this->getRawBits() * rhs.getRawBits();
	ret->setRawBits((int)(mul >> Fixed::_fractionalBits));
	return *ret;
}

Fixed &	Fixed::operator/(Fixed const &rhs)
{
	Fixed		*ret = new Fixed();
	long long	numerator;

	numerator = (this->getRawBits() << (Fixed::_fractionalBits));
	ret->setRawBits((int)(numerator / rhs.getRawBits()));
	return *ret;
}

Fixed &		Fixed::operator++ (void)
{
	this->_rawBits++;
	return *this;
}

Fixed		Fixed::operator++ (int)
{
	Fixed tmp(*this);

	this->_rawBits++;
	return tmp;
}

Fixed &		Fixed::operator-- (void)
{
	this->_rawBits--;
	return *this;
}

Fixed		Fixed::operator-- (int)
{
	Fixed tmp(*this);

	this->_rawBits--;
	return tmp;
}

int Fixed::toInt(void) const
{
	return this->_rawBits >> this->_fractionalBits;
}

float Fixed::toFloat(void) const
{
	int mask = 0;

	for (int i = 0; i < this->_fractionalBits; i++)
		mask = (mask << 1) | 1;
	return (float)(this->toInt()) + (float)(this->_rawBits & mask) / (float)(1 << this->_fractionalBits);
}

Fixed &	Fixed::max(Fixed &a, Fixed &b)
{
	return a >= b ? a : b;
}

const Fixed &	Fixed::max(Fixed const &a, Fixed const &b)
{
	return a >= b ? a : b;
}

Fixed &	Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &	Fixed::min(Fixed const &a, Fixed const &b)
{
	return a < b ? a : b;
}

std::string const	Fixed::toString(void) const
{
	std::ostringstream ss;
	ss << this->toFloat();
	return ss.str();
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}