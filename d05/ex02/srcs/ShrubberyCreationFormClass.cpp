#include "ShrubberyCreationFormClass.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) :
AForm("Shrubbery Creation", 145, 137),
_target(target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src)
{
	*this = src;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	(void)rhs;
	return *this;
}

std::ostream &	operator<< (std::ostream & o, ShrubberyCreationForm const & rhs)
{
	o << rhs.toString();
	return o;
}
void ShrubberyCreationForm::action(void) const
{
	try
	{
		std::ofstream stream;
		stream.open(this->getTarget(), std::fstream::out | std::fstream::app);
		stream << "      /\\" << std::endl;
		stream << "     /\\*\\" << std::endl;
		stream << "    /\\O\\*\\" << std::endl;
		stream << "   /*/\\/\\/\\" << std::endl;
		stream << "  /\\O\\/\\*\\/\\" << std::endl;
		stream << " /\\*\\/\\*\\/\\/\\" << std::endl;
		stream << "/\\O\\/\\/*/\\/O/\\" << std::endl;
		stream << "      ||" << std::endl;
		stream << "      ||" << std::endl;
		stream << "      ||" << std::endl;
		stream.close();
	}
	catch (std::ofstream::failure e)
	{
		std::cerr << "Exception opening/writing/closing file\n";
	}
}

std::string const ShrubberyCreationForm::getTarget(void) const { return (this->_target); }