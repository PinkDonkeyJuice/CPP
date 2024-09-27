/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:02:15 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/19 18:08:14 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ScavTrap Melanchon("Melanchon");
	ScavTrap Zemmour("Zemmour");
	FragTrap Bro("Bro");
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
	Bro.highFivesGuys();
	Bro.highFivesGuys();
	Bro.highFivesGuys();
	Bro.highFivesGuys();
}
