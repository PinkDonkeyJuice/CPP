/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:04:44 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/07 15:54:50 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->_HP = 100;
	this->_EP = 100;
	this->_AD = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
	this->_HP = 100;
	this->_EP = 100;
	this->_AD = 30;
	std::cout << "FragTrap constructor called for " << Name << std::endl;
}


FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << this->_Name << std::endl;
}

FragTrap::FragTrap(const FragTrap &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_Name = ref._Name;
	this->_HP = ref._HP;
	this->_EP = ref._EP;
	this->_AD = ref._AD;
}

FragTrap &FragTrap::operator=(const FragTrap &ref)
{
	this->_Name = ref._Name;
	this->_HP = ref._HP;
	this->_EP = ref._EP;
	this->_AD = ref._AD;
	return *this;
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
