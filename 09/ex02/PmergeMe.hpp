#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <deque>

class PmergeMe
{
	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();

		void	sort_list(std::list<int> *L);
		void	sort_deque(std::deque<int> *D);
		void	print_result(std::list<int> result);

		//Exceptions
		class InvalidArgumentsException: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return("Need a sequence of ints as arguments");
				}
		};
};

