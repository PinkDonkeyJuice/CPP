/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:02:15 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/19 18:01:07 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap Melanchon("Melanchon");
	ScavTrap Zemmour("Zemmour");
	Melanchon.attack("Zemmour");
	Zemmour.takeDamage(0);
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Melanchon.takeDamage(0);
	Melanchon.beRepaired(69);
	Melanchon.guardGate();
}
