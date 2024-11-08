/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:02:15 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/07 14:27:49 by gyvergni         ###   ########.fr       */
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
	Zemmour.beRepaired(69);
	ClapTrap Bardella(Zemmour);
	Bardella.attack("Melanchon");
	Melanchon.takeDamage(0);
	Melanchon.beRepaired(69);
	Melanchon.takeDamage(10);
	Melanchon.beRepaired(69);
}
