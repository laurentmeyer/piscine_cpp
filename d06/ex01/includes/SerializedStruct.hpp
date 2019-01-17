#ifndef SERIALIZEDSTRUCT_HPP
# define SERIALIZEDSTRUCT_HPP

# include <iostream>
# include	"DataStruct.hpp"

struct Serialized
{
  public:
	Serialized(void);
	~Serialized(void);
	char s1[8];
	int n;
	char s2[8];
};

void * serialize(void);
Data * deserialize(void * raw);

#endif