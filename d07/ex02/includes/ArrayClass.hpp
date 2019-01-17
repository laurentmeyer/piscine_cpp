#ifndef ARRAYCLASS_HPP
# define ARRAYCLASS_HPP

#include <iostream>

template <typename T>
class Array
{

  public:
	class OutOfBoundException : public std::exception
	{
	  public:
		OutOfBoundException(void){};
		~OutOfBoundException(void) throw() {};
		OutOfBoundException &operator=(OutOfBoundException const &rhs) { (void)rhs; return *this; };
		virtual char const *what() const throw() { return "Out of bound exception"; };
	};

	Array(void) : _size(0), _array(nullptr){};
	Array(unsigned int n) : _size(n), _array(new T[n]){};
	Array(Array const &src) : _size(src.size()), _array(new T[src.size()]) { *this = src; };
	~Array(void) { delete[] this->_array; };
	Array &operator=(Array const &rhs)
	{
		if (this->size() != rhs.size())
		{
			this->_size = rhs.size();
			delete[] this->_array;
			this->_array = new T[this->size()];
		}
		for (size_t i = 0; i < this->_size; i++)
			this->_array[i] = rhs._array[i];
		return *this;
	};
	T &operator[](size_t i)
	{
		if (i >= this->size())
			throw OutOfBoundException();
		return this->_array[i];
	};
	size_t size(void) const { return this->_size; };

  private:
	size_t _size;
	T *_array;
};

#endif