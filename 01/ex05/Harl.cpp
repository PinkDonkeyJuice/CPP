/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:46:51 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/17 18:12:15 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "We have a rad-x cockroach in daddy's kitchen" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "Wow this cockroach in so humungus. Not only it's body but it's disgusting roach-feet too!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "This cockroach is going to eat us" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "I burned down the house. The cockroach is still alive" << std::endl;
}

void	Harl::complain(std::string level)
{
	void			(Harl::*ptr_complain[]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string		complain_list[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (complain_list[i] == level)
			(this->*ptr_complain[i])();
	}
}