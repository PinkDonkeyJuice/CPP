/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:04:59 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/07 15:53:30 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "ClapTrap.hpp"

#pragma once

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap &ref);
		FragTrap(std::string Name);
		~FragTrap();

		FragTrap &operator=(const FragTrap &ref);
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};
