/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:39:22 by gyvergni          #+#    #+#             */
/*   Updated: 2024/12/16 16:21:58 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _N(0)
{
}

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(const Span &ref) : _N(ref._N), _v(ref._v)
{
}

Span::~Span()
{
}

Span &Span::operator=(const Span &ref)
{
	if (this != &ref)
	{
		this->_N = ref._N;
		this->_v = ref._v;
	}
	return *this;
}

void	Span::addNumber(int n)
{
	if (this->_v.size() == this->_N)
		throw(Span::VectorFullException());
	else
		this->_v.push_back(n);
}

int		Span::shortestSpan()
{
	std::vector<int> vec = this->_v;
	int	shortest;
	std::vector<int>::iterator it;

	if (vec.size() < 2)
		throw(Span::ToofewElementsException());
	std::sort(vec.begin(), vec.end());
	shortest = vec[1] - vec[0];
	for (it = vec.begin(); it < vec.end() - 1; it++)
	{
		if (*(it + 1) - *it < shortest)
			shortest = *(it + 1) - *it;
	}
	return shortest;
}

int	Span::longestSpan()
{
	int longest;
	std::vector<int> vec = this->_v;

	if (vec.size() < 2)
		throw(Span::ToofewElementsException());
	std::sort(vec.begin(), vec.end());
	longest = *(vec.end() - 1) - *(vec.begin());
	return longest;
}

const char	*Span::VectorFullException::what() const throw()
{
	return ("Can't add number, span is full");
}

const char	*Span::ToofewElementsException::what() const throw()
{
	return ("Too few elements to calculate span");
}

void	Span::addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if ((this->_v.size() + (std::distance(start, end))) > this->_N)
		throw(Span::VectorFullException());
	else
		this->_v.insert(this->_v.end(), start, end);
}
