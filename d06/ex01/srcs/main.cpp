#include <iostream>
#include "DataStruct.hpp"
#include "SerializedStruct.hpp"

int main(void)
{
	Data *d = deserialize(serialize());
	std::cout << d->s1 << d->n << d->s2 << std::endl;
	return 0;
}