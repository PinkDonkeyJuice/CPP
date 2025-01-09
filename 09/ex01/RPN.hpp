#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int> _stack;
		std::string _expr;

	public:
		RPN();
		~RPN();
		RPN(const RPN &ref);
		RPN(std::string input);
		RPN &operator=(const RPN &ref);
		void	calculate();
		void	do_op(std::string buffer);

		class InvalidOperationException: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return("Invalid operation");
				}
		};
		class InvalidInputException: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return("Invalid Input");
				}
		};
		class InvalidTypeException: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return("Invalid operation");
				}
		};
};
