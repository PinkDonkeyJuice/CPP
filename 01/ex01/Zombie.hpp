/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:35:04 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/10/28 11:42:08 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	private:
		std::string	_name;

	public:
		Zombie();
		~Zombie();

		void	announce(void);
		void	set_name(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif