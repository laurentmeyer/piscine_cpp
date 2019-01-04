#include "PhonebookClass.hpp"

Phonebook::Phonebook(void)
{
	this->_entry_index = 0;
	// std::cout << "Phonebook created" << std::endl;
	return;
}

Phonebook::~Phonebook(void)
{
	// std::cout << "Phonebook deleted" << std::endl;
	return;
}

int Phonebook::prompt(void)
{
	std::string input;
	Contact 	*contact;

	std::cout << Phonebook::_input_message;
	std::getline(std::cin, input);
	if (std::cin.fail())
		return (0);
	if ("EXIT" == input)
		return (0);
	else if ("ADD" == input)
	{
		if (this->_entry_index < NB_CONTACTS)
		{
			contact = &(this->_entries[this->_entry_index]);
			(this->_entry_index)++;
			return (contact->update());
		}
		std::cout << "Phonebook is full" << std::endl;
	}
	else if ("SEARCH" == input)
	{
		if (this->_entry_index > 0)
			return (Phonebook::search());
		std::cout << "Phonebook is empty" << std::endl;
	}
	return (1);
}

void Phonebook::_printLine(int ac, std::string const *av)
{
	std::streamsize w = std::cout.width();

	std::cout << "|";
	for (int i = 0; i < ac; i++)
	{
		if (av[i].length() > 10)
			std::cout << std::setw(9) << av[i].substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << av[i] << "|";
	}
	std::cout << std::endl;
	std::cout << std::setw(w);
}

int Phonebook::_getIndex(int *dst)
{
	std::string input;

	std::cout << "Enter index to display: ";
	std::getline(std::cin, input);
	if (std::cin.fail())
		return (-1);
	if (std::string::npos == input.find_first_of("0123456789"))
		return (0);
	*dst = std::stoi(input);
	return (1);
}

int Phonebook::search(void)
{
	std::string input;
	int index_success;
	int index;

	Phonebook::_printLine(4, Phonebook::_fieldsToDisplay);
	for (int i = 0; i < this->_entry_index; i++)
	{
		std::string fieldValues[4] =
			{std::to_string(i),
			 this->_entries[i].getField(Phonebook::_fieldsToDisplay[1])->getValue(),
			 this->_entries[i].getField(Phonebook::_fieldsToDisplay[2])->getValue(),
			 this->_entries[i].getField(Phonebook::_fieldsToDisplay[3])->getValue()};
		Phonebook::_printLine(4, fieldValues);
	}
	while ((index_success = Phonebook::_getIndex(&index)) <= 0 || index < 0 || index >= this->_entry_index)
	{
		std::cout << std::endl
				  << "Please enter valid index." << std::endl;
		if (-1 == index_success)
			return (0);
	}
	std::cout << std::endl;
	this->_entries[index].print();
	std::cout << std::endl;
	return (1);
}

const std::string Phonebook::_input_message = "Enter command: ";
const std::string Phonebook::_fieldsToDisplay[] = {"index", "first name", "last name", "nickname"};