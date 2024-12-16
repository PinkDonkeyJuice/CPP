#include <iostream>
#include <string>
#include <stack>
#include <sstream>

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
		void	parse_input(std::string input);
};
