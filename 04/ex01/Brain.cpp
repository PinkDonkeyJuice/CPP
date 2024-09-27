/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:28:09 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/25 19:09:07 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &ref)
{
	for (int i = 0; i < 100; i++)
	{
		if (ref._ideas[i].length() > 0)
			this->_ideas[i].assign(ref._ideas[i]);
	}
	return (*this);
}

Brain::Brain(const Brain &ref)
{
	std::cout << "Brain copy constructor called";
	*this = ref;
}
