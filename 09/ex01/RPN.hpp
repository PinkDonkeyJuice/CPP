#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN &ref);
		RPN(std::string input);
		RPN &operator=(const RPN &ref);
		void	calculate();
		void	do_op(std::string buffer);
	
	private:
		std::stack<int> _stack;
		std::string _expr;
};
