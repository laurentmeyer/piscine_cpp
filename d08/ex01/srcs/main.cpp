#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include "SpanClass.hpp"

int	randomNumber(void) { return std::rand() ; }

int main()
{
	Span sp = Span(5);

	std::cout << std::endl << "Assignment tests" << std::endl;
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	std::srand(time(nullptr));

	sp = Span(1);
	std::cout << std::endl << "Span empty or one element => should throw exception" << std::endl;
	try
	{
		sp.addNumber(1);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (Span::SpanException &e)
	{
		std::cout << e.what() << std::endl;
	}

	// size_t testSize = 31;
	size_t testSize = 1000000;
	sp = Span(30);
	std::vector<int> randomVec(testSize);
	std::generate(randomVec.begin(), randomVec.end(), &randomNumber);

	std::cout << std::endl << "Span size not sufficient for input => should throw exception" << std::endl;
	try
	{
		sp.insert(randomVec.begin(), randomVec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (Span::SpanException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "Test with a large input" << std::endl;
	sp = Span(testSize);
	try
	{
		sp.insert(randomVec.begin(), randomVec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (Span::SpanException &e)
	{
		std::cout << e.what() << std::endl;
	}
}