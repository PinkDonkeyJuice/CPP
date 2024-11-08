/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:39:25 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/07 15:29:17 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>
#include <stdlib.h>

class ClapTrap
{
	private:
		std::string _Name;
		unsigned int	_HP;
		unsigned int	_EP;
		unsigned int	_AD;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap &ref);
		ClapTrap(std::string Name);
		virtual ~ClapTrap();

		ClapTrap &operator=(const ClapTrap &ref);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
