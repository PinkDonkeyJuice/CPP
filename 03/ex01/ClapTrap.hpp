/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:39:25 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/19 18:01:24 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>
#include <stdlib.h>

class ClapTrap
{
	private:
		std::string _Name;
		unsigned int	_HP = 10;
		unsigned int	_EP = 10;
		unsigned int	_AD = 0;

	public:
		ClapTrap();
		ClapTrap(std::string Name);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

