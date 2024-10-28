#include "Array.hpp"
#include <iostream>
#include <cstdlib>

int	main(void)
{
	Array<int> numbers(50);
	int *mirror = new int[50];
	srand(time(NULL));
	for (int i = 0; i < 50; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	{
		Array<int> tmp;
		try
		{
			for (int i = 0; i < 50; i++)
				std::cout << tmp[i] << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		tmp = numbers;
		Array<int> test(tmp);

		try
		{
			for (int i = 0; i < 51; i++)
			{
				std::cout << tmp[i] << std::endl;
				if (tmp[i] != test[i])
				{
					std::cerr << "assignement constructor didn't copy the same value";
					return 1;
				}
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "tmp size is: " << tmp.size() << std::endl;	
	}
	delete[] mirror;
}