/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:02:15 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/07 15:43:13 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap Melanchon("Melanchon");
	ScavTrap Zemmour("Zemmour");
	Melanchon.attack("Zemmour");
	Zemmour.takeDamage(0);
	Melanchon.takeDamage(20);
	Zemmour.attack("Melanchon");
	Melanchon.takeDamage(20);
	Zemmour.attack("Melanchon");
	Melanchon.takeDamage(20);
	Zemmour.attack("Melanchon");
	Melanchon.takeDamage(20);
	Zemmour.attack("Melanchon");
	Melanchon.takeDamage(20);
	Zemmour.attack("Melanchon");
	Melanchon.takeDamage(20);
	Zemmour.attack("Melanchon");
	Melanchon.takeDamage(20);
	Zemmour.attack("Melanchon");
	Melanchon.takeDamage(20);
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Zemmour.attack("Melanchon");
	Melanchon.takeDamage(20);
	Melanchon.beRepaired(69);
	Melanchon.takeDamage(69);
	Melanchon.guardGate();
}
