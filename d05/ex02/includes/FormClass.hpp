#ifndef FormClass_HPP
#define FormClass_HPP

#include <iostream>

class Form;

#include "BureaucratClass.hpp"

class Form
{

  public:
	class AFormException : public std::exception
	{
	  public:
		AFormException(void);
		AFormException(AFormException const &src);
		~AFormException(void) throw();
		AFormException &operator=(AFormException const &rhs);

		virtual char const *what() const throw() = 0;

	  private:
	};

  public:
	class FormNotSignedException : public AFormException
	{
	  public:
		FormNotSignedException(void);
		FormNotSignedException(FormNotSignedException const &src);
		~FormNotSignedException(void) throw();
		FormNotSignedException &operator=(FormNotSignedException const &rhs);

		virtual char const *what() const throw();

	  private:
	};

	class GradeTooLowException : public AFormException
	{
	  public:
		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const &src);
		~GradeTooLowException(void) throw();
		GradeTooLowException &operator=(GradeTooLowException const &rhs);

		virtual char const *what() const throw();

	  private:
	};

	class GradeTooHighException : public AFormException
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
	Form(Form const &src);
	~Form(void);

	bool getSigned(void) const;
	void beSigned(Bureaucrat &b);
	unsigned int getMinGradeSign(void) const;
	unsigned int getMinGradeExecute(void) const;
	std::string const toString(void) const;
	virtual void execute(Bureaucrat const &executor) const;
	virtual void action(void) const = 0;

	Form &operator=(Form const &rhs);

  protected:
	Form(void);

	void _setSigned(bool s);

	bool _signed;
	unsigned int const _minGradeExecute;
	unsigned int const _minGradeSign;
	std::string const getName(void) const;

	std::string const _name;
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif