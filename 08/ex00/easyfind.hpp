#pragma once

#include <cstdlib>
#include <iostream>

template<typename T>
int easyfind(T type, int n)
{
	int i;

	while (type[i] != n)
	{
		i++;
	}
	if (i == type.end())
		throw(CannotFindError());
	return (i);
}

class CannotFindError : public std::exception
{
	public:
		virtual const char *what() const throw();
};

const char *CannotFindError::what() const throw()
{
	return ("Couldn't find requested int in the container\n");
}