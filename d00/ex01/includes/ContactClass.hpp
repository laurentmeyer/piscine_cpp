#ifndef CONTACTCLASS_HPP
# define CONTACTCLASS_HPP

# include "FieldClass.hpp"
# include <iostream>
# define NB_FIELDS 11

class Contact
{

public:
  Contact(void);
  ~Contact(void);

  int update(void);
  Field *getField(std::string fieldName);
  void print(void);

private:
  static const std::string _field_names[NB_FIELDS];
  Field _fields[NB_FIELDS];
};

#endif
