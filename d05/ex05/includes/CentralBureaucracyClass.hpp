#ifndef CENTRALBUREAUCRACYCLASS_HPP
# define CENTRALBUREAUCRACYCLASS_HPP

# include <iostream>
# include "OfficeBlockClass.hpp"
# include "BureaucratClass.hpp"

class CentralBureaucracy {
  public:
	class ACentralBureaucracyException : public std::exception
	{
	public:
		ACentralBureaucracyException(void);
		ACentralBureaucracyException(ACentralBureaucracyException const &src);
		virtual ~ACentralBureaucracyException(void) throw();
		virtual char const *what() const throw() = 0;

	private:
		ACentralBureaucracyException &operator=(ACentralBureaucracyException const &rhs);
	};

	class BureaucratQueueFullException : public ACentralBureaucracyException
	{
	public:
		BureaucratQueueFullException(void);
		BureaucratQueueFullException(BureaucratQueueFullException const &src);
		~BureaucratQueueFullException(void) throw();
		virtual char const *what() const throw();

	private:
		BureaucratQueueFullException &operator=(BureaucratQueueFullException const &rhs);
	};

	class TargetQueueFullException : public ACentralBureaucracyException
	{
	public:
		TargetQueueFullException(void);
		TargetQueueFullException(TargetQueueFullException const &src);
		~TargetQueueFullException(void) throw();
		virtual char const *what() const throw();

	private:
		TargetQueueFullException &operator=(TargetQueueFullException const &rhs);
	};

	class AllOfficesFullException : public ACentralBureaucracyException
	{
	public:
		AllOfficesFullException(void);
		AllOfficesFullException(AllOfficesFullException const &src);
		~AllOfficesFullException(void) throw();
		virtual char const *what() const throw();

	  private:
		AllOfficesFullException &operator=(AllOfficesFullException const &rhs);
	};

	CentralBureaucracy(void);
	~CentralBureaucracy(void);
	void feedBureaucrat(Bureaucrat &bureaucrat);
	void generateRandomTargets(size_t i);
	void queueUp(std::string target);
	void doBureaucracy(void);
	std::string const toString(void) const;

  private:
	CentralBureaucracy(CentralBureaucracy const &src);
	CentralBureaucracy &operator=(CentralBureaucracy const &rhs);

	static std::string const _someRandomNames[];
	static size_t const _blocksCount;
	static size_t const _bureaucratQueueMaxSize;
	static size_t		_targetQueueCount;
	static size_t const _targetQueueMaxSize;
	OfficeBlock *_officeBlocks;
	Bureaucrat **_bureaucratQueue;
	std::string *_targetQueue;
};

std::ostream &operator<<(std::ostream &o, CentralBureaucracy const &rhs);

#endif