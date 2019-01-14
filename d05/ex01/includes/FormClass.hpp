#ifndef FORMCLASS_HPP
# define FORMCLASS_HPP

# include <iostream>

class Form ;

# include "BureaucratClass.hpp"

class Form {

public:
	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const &src);
		~GradeTooLowException(void) throw();
		GradeTooLowException &operator=(GradeTooLowException const &rhs);

		virtual char const *what() const throw();

	private:
	};

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(void);
		GradeTooHighException(GradeTooHighException const &src);
		~GradeTooHighException(void) throw();
		GradeTooHighException &operator=(GradeTooHighException const &rhs);

		virtual char const *what() const throw();

	private:
	};

	Form(std::string const name, unsigned int minSignature, unsigned int minExecution); 
	Form(Form const & src); 
	~Form(void); 


	bool	getSigned(void) const;
	unsigned int getMinGradeSign(void) const;
	unsigned int getMinGradeExecute(void) const;
	void beSigned(Bureaucrat &b);
	std::string const	toString(void) const;

	Form &		operator=(Form const & rhs);

private:
	Form(void); 

	void _setSigned(bool s);

	bool _signed;
	unsigned int const _minGradeExecute;
	unsigned int const _minGradeSign;
		std::string const	getName(void) const;
	
		std::string const	_name;
	
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif