/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:04:59 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/19 18:21:35 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "ClapTrap.hpp"

#pragma once

class FragTrap : public ClapTrap
{
	private:
		std::string _Name;
		unsigned int	_HP = 100;
		unsigned int	_EP = 100;
		unsigned int	_AD = 30;

	public:
		FragTrap();
		FragTrap(std::string Name);
		~FragTrap();

		void	attack(const std::string& target);
		void	highFivesGuys(void);
};
