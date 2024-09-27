/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:29:19 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/19 18:03:10 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	std::cout << "ScavTrap constructor called for " << Name << std::endl;
	this->_Name = Name;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << this->_Name << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_HP > 0 && this->_EP > 0)
	{
		std::cout << "ScavTrap " << this->_Name << " attacks " << target << " causing " << this->_AD << " points of damage!" << std::endl;
		this->_EP--;
	}
	else if (this->_HP == 0)
		std::cout << "ScavTrap " << this->_Name << " can't attack because it has no HP left" << std::endl;
	else
		std::cout << "ScavTrap " << this->_Name << " can't attack because it has no energy left" << std::endl;
}


void	ScavTrap::guardGate()
{
	std::cout << this->_Name << " has entered Gate keeper mode" << std::endl;
}
