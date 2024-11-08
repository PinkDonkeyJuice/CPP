/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:29:19 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/08 10:21:15 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_HP = 100;
	this->_EP = 50;
	this->_AD = 20;
	this->_is_guarding = false;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	this->_HP = 100;
	this->_EP = 50;
	this->_AD = 20;
	this->_is_guarding = false;
	std::cout << "ScavTrap constructor called for " << Name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << this->_Name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_Name = ref._Name;
	this->_HP = ref._HP;
	this->_EP = ref._EP;
	this->_AD = ref._AD;
	this->_is_guarding = ref._is_guarding;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ref)
{
	this->_Name = ref._Name;
	this->_HP = ref._HP;
	this->_EP = ref._EP;
	this->_AD = ref._AD;
	this->_is_guarding = ref._is_guarding;
	return *this;
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
	if (this->_is_guarding)
		std::cout << this->_Name << " is already guarding the gate" << std::endl;
	else if (this->_HP > 0 && this->_EP > 0)
	{
		std::cout << this->_Name << " has entered Gate keeper mode" << std::endl;
		this->_is_guarding = true;
	}
	else
		std::cout << "ScavTrap " << this->_Name << "can't enter Gate keeper mode" << std::endl;
}
