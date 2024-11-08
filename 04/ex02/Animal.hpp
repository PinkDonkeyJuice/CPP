/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:51:35 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/08 14:13:56 by gyvergni         ###   ########.fr       */
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
		Animal(const Animal &ref);
	public:
   	 	virtual ~Animal();

		virtual void	makeSound() const = 0;
		virtual std::string	getType() const;
		Animal &operator=(Animal const &src);

};