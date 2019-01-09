#include "FixedClass.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = (int)roundf(f * (1 << Fixed::_fractionalBits));
	return;
}

Fixed::Fixed(int const i)
{
	std::cout << "Int constructor called" << std::endl;
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
	std::cout << "Destructor called" << std::endl;
	return;
}

int Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw) { this->_rawBits = raw; }

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
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
	//
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

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}