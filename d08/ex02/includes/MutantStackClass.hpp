#ifndef MUTANTSTACKCLASS_HPP
#define MUTANTSTACKCLASS_HPP

#include <iostream>
#include <iterator>
#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{

  public:

	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack(void){};
	~MutantStack(void){};

	iterator begin(void) { return this->c.begin(); }
	iterator end(void) { return this->c.end(); }

  private:
};

#endif