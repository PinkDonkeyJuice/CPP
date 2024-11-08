/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:20:44 by gyvergni          #+#    #+#             */
/*   Updated: 2024/11/08 14:20:46 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;

	public:
	    WrongAnimal();
		WrongAnimal(const WrongAnimal &ref);
	    ~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &ref);
	void	makeSound() const;
	std::string	getType() const;
};
