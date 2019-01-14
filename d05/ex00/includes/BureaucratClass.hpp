#ifndef BUREAUCRATCLASS_HPP
#define BUREAUCRATCLASS_HPP

#include <iostream>

class Bureaucrat
{
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

	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat(void);

	Bureaucrat &operator=(Bureaucrat const &rhs);

	Bureaucrat(std::string name);
	std::string const toString(void) const;
	std::string const getName(void) const;
	unsigned int getGrade(void) const;
	void promote(void);
	void retrograde(void);

private:
	static unsigned int const _maxGrade;
	static unsigned int const _minGrade;
	void _setGrade(unsigned int grade);
	std::string const _name;
	unsigned int _grade;

	Bureaucrat(void);
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif