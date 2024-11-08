/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:02:15 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/08 10:19:54 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ScavTrap Georges("Georges");
	FragTrap Cyril("Cyril");
	DiamondTrap *Joe = new DiamondTrap("Joe");
	Cyril.takeDamage(10);
	
	DiamondTrap Eric("Eric");
	Eric.whoAmI();
	
	DiamondTrap Emmanuel(Eric);
	DiamondTrap Patrice("Patrice");
	
	Patrice.whoAmI();
	Patrice = Emmanuel;
	Patrice.whoAmI();
	delete(Joe);
}
