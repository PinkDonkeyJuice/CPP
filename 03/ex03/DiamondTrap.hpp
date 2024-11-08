/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:25:24 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/07 14:43:18 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#pragma once

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _Name;
	
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap &ref);
		DiamondTrap(std::string Name);
		virtual ~DiamondTrap();

		DiamondTrap &operator=(const DiamondTrap &ref);
		void	attack(const std::string& target);
		void	whoAmI();
};
