#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{

	if (argc < 2)
	{
		std::cout << "Need at least one int to sort\n";
		return 1;
	}
	try 
	{
		std::cout << "With list:" << std::endl;
		PmergeMe<std::list<Element *> > merge_list(argc, argv);
		std::cout << "With deque:" << std::endl;
		PmergeMe<std::deque<Element *> > merge_deque(argc, argv);
	}
	catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
