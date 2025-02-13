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

	if (this->_stack.size() < 2)
		throw (RPN::InvalidInputException("need at least 2 numbers in the stack to do an operation"));
	val1 = static_cast<long long>(this->_stack.top());
	this->_stack.pop();
	val2 = static_cast<long long>(this->_stack.top());
	this->_stack.pop();
	if (buffer[0] == '+')
		result = val1 + val2;
	if (buffer[0] == '-')
		result = val2 - val1;
	if (buffer[0] == '*')
		result = val2 * val1;
	if (buffer[0] == '/')
	{
		if (val1 == 0)
			throw(RPN::InvalidOperationException("can't divide by 0"));
		result = val2 / val1;
	}
	if (result > 2147483647 || result < -2147483648)
		throw(RPN::InvalidOperationException("an operation resulted in an int overflow"));
	this->_stack.push(static_cast<int>(result));
}

bool	RPN::is_op(std::string buffer)
{
	if (buffer.length() != 1)
		throw(RPN::InvalidInputException("need one space between all characters"));
	if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '/' || buffer[0] == '*')
		return true;
	return false;
}

bool	RPN::is_num(std::string buffer)
{
	if (buffer.length() != 1)
		throw(RPN::InvalidInputException("need one space between all characters"));
	if (buffer[0] >= 48 && buffer[0] <= 57)
		return true;
	return false;
}

void	RPN::calculate()
{
	std::string input = this->_expr;
	std::string buffer;
	size_t		n_nums = 0;
	size_t		n_ops = 0;

	std::istringstream ss(input);
	while (std::getline(ss, buffer, ' '))
	{
		if (is_op(buffer) == true)
		{
			do_op(buffer);
			n_ops++;
		}
		else if (is_num(buffer) == true)
		{
			this->_stack.push(atoi(buffer.c_str()));
			n_nums++;
		}
		else
			throw (RPN::InvalidInputException("only numbers between 0 and 9, and [+, -, *, /] operation signs are allowed"));
	}
	if (n_ops != n_nums - 1)
		throw (InvalidInputException("there must be one less operation than numbers in order to work"));
	std::cout << this->_stack.top() << std::endl;
}
