#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try 
	{
		PmergeMe(argc, argv);
	}
	catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}