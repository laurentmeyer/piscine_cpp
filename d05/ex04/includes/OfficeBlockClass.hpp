#ifndef OFFICEBLOCKCLASS_HPP
# define OFFICEBLOCKCLASS_HPP

# include <iostream>
# include <string>
# include "InternClass.hpp"
# include "BureaucratClass.hpp"
# include "FormClass.hpp"

class OfficeBlock
{

public:
	class AOfficeBlockException : public std::exception
	{
	public:
		AOfficeBlockException(void);
		AOfficeBlockException(AOfficeBlockException const &src);
		virtual ~AOfficeBlockException(void) throw();
		virtual char const *what() const throw() = 0;

	private:
		AOfficeBlockException &operator=(AOfficeBlockException const &rhs);
	};

	class MissingTeamMemberException : public AOfficeBlockException
	{
	public:
		MissingTeamMemberException(void);
		MissingTeamMemberException(MissingTeamMemberException const &src);
		~MissingTeamMemberException(void) throw();
		virtual char const *what() const throw();

	private:
		MissingTeamMemberException &operator=(MissingTeamMemberException const &rhs);
	};

	OfficeBlock(void);
	OfficeBlock(Intern &intern, Bureaucrat &signator, Bureaucrat &executor);
	~OfficeBlock(void);

	void	doBureaucracy(std::string const formName, std::string const target) const;
	void	setIntern(Intern &intern);
	void	setSigner(Bureaucrat &signer);
	void	setExecutor(Bureaucrat &executor);

private:
	OfficeBlock(OfficeBlock const &src);
	OfficeBlock &operator=(OfficeBlock const &rhs);

	Intern *_intern;
	Bureaucrat *_signator;
	Bureaucrat *_executor;
};

#endif