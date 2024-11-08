/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:25:24 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/07 15:51:37 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "ClapTrap.hpp"

#pragma once

class ScavTrap : virtual public ClapTrap
{
	private:
		bool _is_guarding;
	
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &ref);
		ScavTrap(std::string Name);
		~ScavTrap();

		ScavTrap &operator=(const ScavTrap &ref);
		void	attack(const std::string& target);
		void	guardGate();
};
