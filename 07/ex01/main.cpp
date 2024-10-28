#include <iostream>
#include "iter.hpp"

void	increment(int &i)
{
	i++;
}

void	ft_toupper(char &c)
{
	c = std::toupper(c);
}

void	printc_array(char &c)
{
	std::cout << c << std::endl;
}

void	printi_array(int &c)
{
	std::cout << c << std::endl;
}

int	main(void)
{
	int iarray[5] = {0, 1, 2, 3, 4};
	char str[] = {'a', 'b', 'c'};

	iter(iarray, 5, increment);
	iter(iarray, 5, printi_array);

	iter(str, 3, ft_toupper);
	iter(str, 3, printc_array);
}