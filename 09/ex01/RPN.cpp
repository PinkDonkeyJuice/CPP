#include "RPN.hpp"

RPN::RPN()
{
};

RPN::RPN(std::string input) : _expr(input)
{
}

RPN::RPN(const RPN &ref)
{
	*this = ref;
}

RPN::~RPN()
{
}

RPN	&RPN::operator=(const RPN &ref)
{
	this->_stack = ref._stack;
	this->_expr = ref._expr;
	return *this;
}

void	RPN::do_op(std::string buffer)
{
	long long val1;
	long long val2;
	long long result;

	if (buffer.length() != 1)
		throw(std::exception());
	val1 = static_cast<long long>(this->_stack.top());
	this->_stack.pop();
	val2 = static_cast<long long>(this->_stack.top());
	if (buffer[0] == '+')
		result = val1 + val2;
	if (buffer[0] == '-')
		result = val2 - val1;
	if (buffer[0] == '*')
		result = val2 * val1;
	if (buffer[0] == '/')
	{
		if (val1 == 0)
			throw(std::exception());
		result = val2 / val1;
	}
	if (result > 2147483647 || result < -2147483648)
		throw(std::exception());
	this->_stack.push(static_cast<int>(result));
}		

void	RPN::calculate()
{
	std::string input = this->_expr;
	std::string buffer;
	int			value;

	std::istringstream ss(input);
	std::getline(ss, buffer, ' ');
	if (!(value = std::atoi(buffer.c_str())))
	{
		throw(std::exception());
	}
	this->_stack.push(value);
	while (std::getline(ss, buffer, ' '))
	{
		if (!(value = std::atoi(buffer.c_str())))
		{
			throw(std::exception());
		}
		this->_stack.push(value);
		if (!std::getline(ss, buffer, ' '))
		{
			throw(std::exception());
		}
		do_op(buffer);
	}
	std::cout << this->_stack.top() << std::endl;
}
