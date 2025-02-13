#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;
	mstack.push(6);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << mstack.size() << std::endl;
	std::cout << std::endl;
	
	//forward
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator itend = mstack.end();
	++it;
	*it = 18;
	--it;
	while (it != itend)
	{
		std::cout << "iterator: " << *it << std::endl;
		++it;
	}
	std::cout << std::endl;

	//reverse
	MutantStack<int>::reverse_iterator reverse_it = mstack.rbegin();
	MutantStack<int>::reverse_iterator reverse_itend = mstack.rend();
	
	while (reverse_it != reverse_itend)
	{
		std::cout << "reverse: " << *reverse_it << std::endl;
		++reverse_it;
	}
	std::cout << std::endl;

	//const forward
	MutantStack<int>::const_iterator c_it = mstack.begin();
	MutantStack<int>::iterator c_itend = mstack.end();

	while (c_it != c_itend)
	{
		std::cout << "const_iterator: " << *c_it << std::endl;
		++c_it;
	}
	std::cout << std::endl;

	//const reverse
	MutantStack<int>::const_reverse_iterator c_reverse_it = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator c_reverse_itend = mstack.rend();
	
	while (c_reverse_it != c_reverse_itend)
	{
		std::cout << "const_reverse: " << *c_reverse_it << std::endl;
		++c_reverse_it;
	}
	std::stack<int> s(mstack);
	return 0;
}