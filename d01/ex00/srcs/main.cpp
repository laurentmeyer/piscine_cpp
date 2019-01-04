#include <iostream>
#include "PonyClass.hpp"

int main(void)
{
	Pony	ponyOnTheStack;
	Pony	*ponyOnTheHeap = new Pony("Pouet Pouet");

	ponyOnTheHeap->setLegs(42);
	delete ponyOnTheHeap;
	return (0);
}