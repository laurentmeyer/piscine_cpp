#ifndef ROBOTOMYREQUESTFORMCLASS_HPP
#define ROBOTOMYREQUESTFORMCLASS_HPP

#include <iostream>
#include <string>
#include "FormClass.hpp"

class RobotomyRequestForm : public Form
{
  public:

	class RobotomyFailureException : public Form::AFormException
	{
	public:
		RobotomyFailureException(void);
		RobotomyFailureException(RobotomyFailureException const &src);
		~RobotomyFailureException(void) throw();
		RobotomyFailureException &operator=(RobotomyFailureException const &rhs);

		virtual char const *what() const throw();

	private:
	};

	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	~RobotomyRequestForm(void);

	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

	std::string const getTarget(void) const;
	virtual void action(void) const;

  private:
	RobotomyRequestForm(void);
	std::string const _target;
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &rhs);

#endif