/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:25:24 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/19 18:21:41 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "ClapTrap.hpp"

#pragma once

class ScavTrap : public ClapTrap
{
	private:
		std::string _Name;
		unsigned int	_HP = 100;
		unsigned int	_EP = 50;
		unsigned int	_AD = 20;

	public:
		ScavTrap();
		ScavTrap(std::string Name);
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();
};
