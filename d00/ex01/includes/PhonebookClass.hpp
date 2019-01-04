#ifndef PHONEBOOKCLASS_HPP
# define PHONEBOOKCLASS_HPP

# include <iostream>
# include <iomanip>
# include "ContactClass.hpp"

# define NB_CONTACTS 8

class Phonebook {

public: 

    Phonebook(void); 
    ~Phonebook(void); 

    int                 prompt(void);
    int                 search(void);


private:

    static void					_printLine(int ac, std::string const *av);
	static int					_getIndex(int *dst);
	static const std::string 	_fieldsToDisplay[4];
	static const std::string    _input_message;
    Contact                     _entries[NB_CONTACTS];
    int                         _entry_index;

};


#endif