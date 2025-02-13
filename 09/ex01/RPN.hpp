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
		bool	is_op(std::string buffer);
		bool	is_num(std::string buffer);

		class InvalidOperationException: public std::exception
		{
			private:
				std::string _message;
			public:
				InvalidOperationException(std::string message)
				{
					_message = "Invalid operation: " + message;
				}
				virtual ~InvalidOperationException() throw()
				{
				}
				const char *what() const throw()
				{
					return(_message.c_str());
				}
		};
		class InvalidInputException: public std::exception
		{
			private:
				std::string _message;
			public:
				InvalidInputException(std::string message)
				{
					_message = "Invalid input: " + message;
				}
				virtual ~InvalidInputException() throw()
				{
				}
				const char *what() const throw()
				{
					return(_message.c_str());
				}
		};
		class InvalidTypeException: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return("Invalid operation");
				}
				virtual ~InvalidTypeException() throw()
				{
				}
		};
};
