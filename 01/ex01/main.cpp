/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:55:03 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/08/08 11:26:37 by pinkdonkeyj      ###   ########.fr       */
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
	for (size_t i; i < N; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}