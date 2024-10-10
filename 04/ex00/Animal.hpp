/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:51:35 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/27 10:48:49 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#pragma once

class Animal
{
	protected:
		std::string _type;

	public:
   		Animal();
		Animal(const Animal &ref);
   	 	virtual ~Animal();

		virtual void	makeSound() const;
		virtual std::string	getType() const;
		Animal &operator=(Animal const &newAnimal);

};