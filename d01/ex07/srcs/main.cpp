#include "ReplaceClass.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "usage: ./replace [filename] [s1] [s2]" << std::endl;
		return (0);
	}

	std::ifstream		ifs;
	std::ofstream		ofs;
	std::stringstream	buffer;
	Replace 			replace(av[2], av[3]);

	ifs.open(av[1], std::ios_base::in);
	buffer << ifs.rdbuf();
	ifs.close();

	ofs.open(av[1], std::ios_base::out | std::ios_base::trunc);
	ofs << replace.replace(buffer.str());
	ofs.close();

	return (0);
}