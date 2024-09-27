/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:24:29 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/17 16:07:59 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string	_name;
	Weapon *_weapon;
public:
	HumanB(std::string name);
	~HumanB();

	void	setWeapon(Weapon& weapon);
	void	attack(void);
};

#endif