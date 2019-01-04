#include "ContactClass.hpp"

const std::string Contact::_field_names[] = {"first name", "last name", "nickname", "login", "postal address", "email address", "phone number", "birthday date", "favorite meal", "underwear color", "darkest secret"};

Contact::Contact(void) {
    for (int i = 0; i < NB_FIELDS; i++)
        this->_fields[i].setName(Contact::_field_names[i]);
    return;
};

Contact::~Contact(void) {
    return;
};

int Contact::update(void)
{
    int         i = 0;

    while (i < NB_FIELDS)
        if (0 == this->_fields[i++].setValue())
            return (0);
    return (1);
}

Field *Contact::getField (std::string fieldName)
{
    for (int i = 0; i < NB_FIELDS; i++)
        if (fieldName == this->_fields[i].getName())
            return (this->_fields + i);
    return (NULL);
}

void    Contact::print(void) {
    for (int i = 0; i < NB_FIELDS; i++)
        std::cout << this->_fields[i].toString() << std::endl;
}