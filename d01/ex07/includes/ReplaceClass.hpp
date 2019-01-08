#ifndef REPLACECLASS_HPP
# define REPLACECLASS_HPP

# include <string>

class Replace {

public: 

	typedef Replace	t;
	Replace(std::string const s1, std::string const s2); 
	~Replace(void); 

	std::string const	replace(std::string const line);

private:
	std::string const	_s1;
	std::string const	_s2;
	Replace(void); 

};


#endif