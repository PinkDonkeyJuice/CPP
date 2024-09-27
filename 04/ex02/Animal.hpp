/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:51:35 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/25 19:13:42 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#pragma once

class Animal
{
	protected:
		std::string _type;
   		Animal();

	public:
		Animal(const Animal &ref);
   	 	virtual ~Animal();

		virtual void	makeSound() const;
		virtual std::string	getType() const;
		Animal &operator=(Animal const &src);

};