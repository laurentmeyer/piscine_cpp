#ifndef FIELDCLASS_HPP
# define FIELDCLASS_HPP

# include <iostream>

class Field {

public: 

	typedef Field	t;
	Field(void); 
	Field(std::string name); 
	~Field(void); 

	std::string	getName(void) const;
	void		setName(std::string Name);
	std::string	getValue(void) const;
	int			setValue(void);
	std::string	toString(void);

private:

	std::string 		_name;
	std::string			_value;

};


#endif