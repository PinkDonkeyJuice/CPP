/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:28:09 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/08 14:04:06 by gyvergni         ###   ########.fr       */
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
	std::cout << "Brain assignement called";
	for (int i = 0; i < 100; i++)
	{
		if (ref._ideas[i].length() > 0)
			this->_ideas[i].assign(ref._ideas[i]);
	}
	return (*this);
}

Brain::Brain(const Brain &ref)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = ref;
}

std::string Brain::getIdea(int i)
{
	return this->_ideas[i];
}

void	Brain::brain_setIdea(int i, std::string idea)
{
	if (i >= 0 && i < 100)
		(this->_ideas[i]) = idea;
}
