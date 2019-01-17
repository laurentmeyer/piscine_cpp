#include "SpanClass.hpp"
#include <iostream>
#include <numeric>
#include <vector>

Span::Span(unsigned int n) : _n(n)
{
	return;
}

Span::~Span(void)
{
	return;
}

Span::Span(Span const &src) : _n(src._n)
{
	*this = src;
	return;
}

Span &Span::operator=(Span const &rhs)
{
	this->_n = rhs._n;
	this->_values = rhs._values;
	return *this;
}

int Span::shortestSpan(void)
{
	if (this->_values.size() <= 1)
		throw Span::SpanException();
	int	result[this->_values.size() - 1];
	std::adjacent_difference(this->_values.begin(), this->_values.end(), result);
	return *(std::min_element(result, result + this->_values.size() - 1));
}

int Span::longestSpan(void)
{
	if (this->_values.size() <= 1)
		throw Span::SpanException();
	return *(std::max_element(this->_values.begin(), this->_values.end()))
		-  *(std::min_element(this->_values.begin(), this->_values.end()));

}

void Span::addNumber(int n)
{
	if (this->_values.size() >= this->_n)
		throw Span::OutOfBoundsException();
	this->_values.insert(n);
}

Span::SpanException::SpanException(void) {}
Span::SpanException::~SpanException(void) throw() {}
char const *Span::SpanException::what() const throw() { return "Span exception"; }
Span::SpanException &Span::SpanException::operator=(Span::SpanException const &rhs)
{
	(void)rhs;
	return *this;
}

Span::OutOfBoundsException::OutOfBoundsException(void) {}
Span::OutOfBoundsException::~OutOfBoundsException(void) throw() {}
char const *Span::OutOfBoundsException::what() const throw() { return "Out of bounds exception"; }
Span::OutOfBoundsException &Span::OutOfBoundsException::operator=(Span::OutOfBoundsException const &rhs)
{
	(void)rhs;
	return *this;
}