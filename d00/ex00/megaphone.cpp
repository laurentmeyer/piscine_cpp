#include <iostream>
#include <cctype>

int main(int ac, char *av[])
{
	char	c;

	if (1 == ac)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < ac; i++)
		for (int j = 0; (c = av[i][j]) != '\0'; j++)
			putchar(toupper(c));
	std::cout << std::endl;
	return (0);
}