/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:02:15 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/19 17:13:19 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Melanchon = ClapTrap("Melanchon");
	ClapTrap Zemmour = ClapTrap("Zemmour");
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
}
