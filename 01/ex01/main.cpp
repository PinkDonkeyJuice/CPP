/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:55:03 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/10/11 14:28:08 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	std::string name;
	size_t		N;

	std::cout << "Name of the zombies: " << std::flush;
	std::cin >> name;
	std::cout << "Number of zombies: ";
	std::cin >> N;

	horde = zombieHorde(N, name);
	for (size_t i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}