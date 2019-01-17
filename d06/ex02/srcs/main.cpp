#include <iostream>
#include <ctime>

class Base { public: virtual ~Base(void){} };

class A : public Base
{
  public:
	A(void) { this->_useless = 0 ;};

  private:
	char _useless;
};

class B : public Base
{
  public:
	B(void) { this->_useless = 0 ;};

  private:
	char _useless;
};

class C : public Base
{
  public:
	C(void) { this->_useless = 0 ;};

  private:
	char _useless;
};

Base *generate(void)
{
	std::srand(time(nullptr));
	size_t i = std::rand() % 3;
	if (0 == i)
		return new A();
	if (1 == i)
		return new B();
	return new C();
}

void identify_from_reference( Base & p )
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::bad_cast &bc)
	{
		(void)bc;
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::bad_cast &bc)
	{
		(void)bc;
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::bad_cast &bc)
	{
		(void)bc;
	}
	std::cout << "Impossible to determine child" << std::endl;
}

void identify_from_pointer( Base * p )
{
	A *a = dynamic_cast<A *>(p);
	if (nullptr != a)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	B *b = dynamic_cast<B *>(p);
	if (nullptr != b)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	C *c = dynamic_cast<C *>(p);
	if (nullptr != c)
	{
		std::cout << "C" << std::endl;
		return ;
	}
	std::cout << "Impossible to determine child" << std::endl;
}

int main(void)
{
	Base *base = generate();

	identify_from_pointer(base);
	identify_from_reference(*base);
	return 0;
}