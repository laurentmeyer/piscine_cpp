#include <iostream>
#include <string>
#include "FixedClass.hpp"

int				innermost_parenthesis(std::string const str, size_t *s, size_t *e)
{
	if (std::string::npos == (*s =str.find_last_of("(")))
	{
		if (std::string::npos == str.find_first_of(")"))
			return (0);
		return (-1);
	}
	if (std::string::npos == (*e = str.find_first_of(")", *s)))
		return (-1);
	return (1);
}

std::string const	eval_without_operators(std::string const expr)
{
	size_t		start;
	size_t		end;

	if (std::string::npos == (start = expr.find_first_of("0123456789.-")))
	{
		std::cout << "error near {" << expr << "}" << std::endl;
		exit(-1);
	}
	if (std::string::npos == (end = expr.find_first_not_of("0123456789.", start + 1)))
		return expr.substr(start);
	if (std::string::npos != expr.find_first_not_of(" \t", end + 1))
	{
		std::cout << "error near {" << expr.substr(end + 1) << "}" << std::endl;
		exit(-1);
	}
	return expr.substr(start, end - start + 1);
}

std::string const	eval_without_add_sub(std::string const expr)
{
	size_t				pos;
	std::string			first_operator;
	std::string			lhs;
	Fixed				l;
	std::string			rhs;
	Fixed				r;

	if (std::string::npos != (pos = expr.find(" / ")) || std::string::npos != (pos = expr.find(" * ")))
	{
		first_operator = expr.substr(pos, 3);
		lhs = expr.substr(0, pos);
		rhs = expr.substr(pos + 3);
		l = Fixed(std::stof(eval_without_operators(lhs)));
		r = Fixed(std::stof(eval_without_add_sub(rhs)));
		if (" * " == first_operator)
			return ((l * r).toString());
		return ((l / r).toString());
	}
	return eval_without_operators(expr);
}

std::string const	eval_without_parenthesis(std::string const expr)
{
	size_t				pos;
	std::string			first_operator;
	std::string			lhs;
	Fixed				l;
	std::string			rhs;
	Fixed				r;

	if (std::string::npos != (pos = expr.find(" - ")) || std::string::npos != (pos = expr.find(" + ")))
	{
		first_operator = expr.substr(pos, 3);
		lhs = expr.substr(0, pos);
		rhs = expr.substr(pos + 3);
		l = Fixed(std::stof(eval_without_add_sub(lhs)));
		std::string tmp = eval_without_parenthesis(rhs);
		r = Fixed(std::stof(eval_without_parenthesis(rhs)));
		if (" + " == first_operator)
			return ((l + r).toString());
		return ((l - r).toString());
	}
	return eval_without_add_sub(expr);
}

std::string const eval(std::string const expr)
{
	size_t start;
	size_t end;
	int parenthesis;

	if (-1 == (parenthesis = innermost_parenthesis(expr, &start, &end)))
		return "error";
	if (1 == parenthesis)
		return eval(expr.substr(0, start) + eval(expr.substr(start + 1, end - start - 1)) + expr.substr(end + 1, expr.length() - end - 1));
	return eval_without_parenthesis(expr);
}

int main(int ac, char **av)
{
	if (2 != ac)
		std::cout << "usage: ./eval_expr [expression_string]" << std::endl;
	else
		std::cout << eval(av[1]) << std::endl;
	return 0;
}