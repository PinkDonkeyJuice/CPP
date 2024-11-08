/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:53:34 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/08 11:34:23 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _brain;
	public:
    	Cat();
		Cat(const Cat &ref);
   		~Cat();
		
		void	setIdea(int i, std::string idea);
		void	getIdeas();
		void	makeSound() const;
		Cat &operator=(Cat const &newCat);
};