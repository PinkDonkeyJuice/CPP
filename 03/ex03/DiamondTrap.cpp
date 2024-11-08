/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:29:19 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/08 10:21:38 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name")
{
	this->_Name = "Default";
	this->_HP = FragTrap::_HP;
	this->_EP = ScavTrap:: _EP;
	this->_AD = FragTrap:: _AD;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name + "_clap_name")
{
	this->_Name = Name;
	this->_HP = FragTrap::_HP;
	this->_EP = ScavTrap:: _EP;
	this->_AD = FragTrap:: _AD;
	std::cout << "DiamondTrap constructor called for " << Name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << this->_Name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) : ClapTrap(ref), ScavTrap(ref), FragTrap(ref)
{
	*this = ref;
	ClapTrap::_Name = this->_Name + "_clap_name";
	std::cout << "Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &ref)
{
	this->_Name = ref._Name;
	ClapTrap::_Name = this->_Name + "_clap_name";
	this->_HP = ref._HP;
	this->_EP = ref._EP;
	this->_AD = ref._AD;
	return *this;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->_Name << " and I come from ClapTrap : " << ClapTrap::_Name << std::endl;
}
