/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:44:08 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/27 10:41:04 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
	this->_Name = "default";
}

ClapTrap::ClapTrap(std::string Name)
{
	std::cout << "ClapTrap constructor called for " << Name << std::endl;
	this->_Name = Name;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << this->_Name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_Name = ref._Name;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ref)
{
	this->_Name = ref._Name;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_HP > 0 && this->_EP > 0)
	{
		std::cout << this->_Name << " attacks " << target << " causing " << this->_AD << " points of damage!" << std::endl;
		this->_EP--;
	}
	else if (this->_HP == 0)
		std::cout << this->_Name << " can't attack because it has no HP left" << std::endl;
	else
		std::cout << this->_Name << " can't attack because it has no energy left" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_Name << " took " << amount << " points of damage" << std::endl;
	if (this->_HP > amount)
		this->_HP -= amount;
	else
	{
		this->_HP = 0;
		std::cout << this->_Name << " is KO." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_HP > 0 && this->_EP > 0)
	{
		std::cout << this->_Name << " repaires " << amount << " HP!" << std::endl;
	}
	else if (this->_HP == 0)
		std::cout << this->_Name << " can't repair because it has no HP left" << std::endl;
	else
		std::cout << this->_Name << " can't repair because it has no energy left" << std::endl;
}
