#ifndef AFORMCLASS_HPP
#define AFORMCLASS_HPP

#include <iostream>

class AForm;

#include "BureaucratClass.hpp"

class AForm
{

  public:
	class FormNotSignedException : public std::exception
	{
	  public:
		FormNotSignedException(void);
		FormNotSignedException(FormNotSignedException const &src);
		~FormNotSignedException(void) throw();
		FormNotSignedException &operator=(FormNotSignedException const &rhs);

		virtual char const *what() const throw();

	  private:
	};

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

	AForm(std::string const name, unsigned int minSignature, unsigned int minExecution);
	AForm(AForm const &src);
	~AForm(void);

	bool getSigned(void) const;
	void beSigned(Bureaucrat &b);
	unsigned int getMinGradeSign(void) const;
	unsigned int getMinGradeExecute(void) const;
	std::string const toString(void) const;
	// virtual void checkRights(Bureaucrat const &e) const;
	virtual void execute(Bureaucrat const &executor) const;
	virtual void action(void) const = 0;

	AForm &operator=(AForm const &rhs);

  protected:
	AForm(void);

	void _setSigned(bool s);

	bool _signed;
	unsigned int const _minGradeExecute;
	unsigned int const _minGradeSign;
	std::string const getName(void) const;

	std::string const _name;
};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif