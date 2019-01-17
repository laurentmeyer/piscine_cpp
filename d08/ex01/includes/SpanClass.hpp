#ifndef SPANCLASS_HPP
# define SPANCLASS_HPP

# include <iostream>
# include <set>

class Span
{

  public:
	class SpanException : std::exception
	{
	  public:
		SpanException(void);
		virtual ~SpanException(void) throw();
		SpanException(SpanException const &src);
		SpanException &operator=(SpanException const &rhs);
		char const *what(void) const throw();
	};

	class OutOfBoundsException : public SpanException
	{
	  public:
		OutOfBoundsException(void);
		virtual ~OutOfBoundsException(void) throw();
		OutOfBoundsException(OutOfBoundsException const &src);
		OutOfBoundsException &operator=(OutOfBoundsException const &rhs);
		char const *what(void) const throw();
	};

	Span(unsigned int n);
	~Span(void);
	Span(Span const &src);
	Span &operator=(Span const &rhs);
	int		shortestSpan(void);
	int		longestSpan(void);
	void	addNumber(int n);
	template <class InputIterator>
	void	insert(InputIterator first, InputIterator last) {
		size_t len = last - first;
		if (this->_values.size() + len <= this->_n)
		{
			this->_values.insert(first, last);
			return ;
		}
		len = this->_n - this->_values.size();
		this->_values.insert(first, first + len);
		throw Span::OutOfBoundsException();
	};


  private:
	Span(void);
	std::string const toString(void) const;

	size_t 			_n;
	std::multiset<int>	_values;
};

#endif