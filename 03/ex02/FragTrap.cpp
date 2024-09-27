/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:04:44 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/19 18:07:23 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
	std::cout << "FragTrap constructor called for " << Name << std::endl;
	this->_Name = Name;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << this->_Name << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_HP > 0 && this->_EP > 0)
	{
		std::cout << "FragTrap " << this->_Name << " attacks " << target << " causing " << this->_AD << " points of damage!" << std::endl;
		this->_EP--;
	}
	else if (this->_HP == 0)
		std::cout << "FragTrap " << this->_Name << " can't attack because it has no HP left" << std::endl;
	else
		std::cout << "FragTrap " << this->_Name << " can't attack because it has no energy left" << std::endl;
}


void	FragTrap::highFivesGuys()
{
	std::cout << this->_Name << " requests a high fives bro!" << std::endl;
}
