/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:53:34 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/27 10:50:36 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	private:

	public:
    	Cat();
		Cat(const Cat &ref);
   		~Cat();

		void	makeSound() const;
		Cat &operator=(Cat const &newCat);
};