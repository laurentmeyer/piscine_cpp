#include "SerializedStruct.hpp"
#include <ctime>

Serialized::Serialized(void)
{
	std::srand(time(nullptr));

	for (size_t i = 0; i < 8; i++)
		this->s1[i] = std::rand() % 26 + 'a';
	this->n = std::rand();
	for (size_t i = 0; i < 8; i++)
		this->s2[i] = std::rand() % 26 + 'a';
	return;
}

Serialized::~Serialized(void)
{
	return;
}

void * serialize(void)
{
	return new Serialized();
}

Data * deserialize(void * raw)
{
	char	c1[9] = {0};
	int		n;
	char	c2[9] = {0};
	Data	*d = new Data();

	Serialized *s = reinterpret_cast<Serialized *>(raw);
	for (size_t i = 0; i < 8; i++)
		c1[i] = s->s1[i];
	n = s->n;
	for (size_t i = 0; i < 8; i++)
		c2[i] = s->s2[i];
	d->s1 = std::string(c1);
	d->n = n;
	d->s2 = std::string(c2);
	return d;
}