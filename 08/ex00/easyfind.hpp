#pragma once

#include <cstdlib>
#include <iostream>
#include <algorithm>

class CannotFindError : public std::exception
{
	public:
		virtual const char *what() const throw();
};

const char *CannotFindError::what() const throw()
{
	return ("Couldn't find requested int in the container\n");
}

template<typename T>
void easyfind(T container, int n)
{
	typename T::iterator i;

	i = std::find(container.begin(), container.end(), n);
	if (i == container.end())
		throw(CannotFindError());
	std::cout << "Found " << *i << std::endl;
}
