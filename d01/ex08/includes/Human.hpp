#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <string>
class Human
{
private:
	typedef void		(*funptr)(std::string const &tarjget);
	void				meleeAttack(std::string const &target);
	void				rangedAttack(std::string const &target);
	void				intimidatingShout(std::string const &target);
	// static funptr const	_actions[];
	funptr const		_actions[];
	static std::string	_actionNames[];

public:
	Human(void);
	~Human(void);

	void				action(std::string const &action_name, std::string const &target);
};

#endif