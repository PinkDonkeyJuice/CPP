/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:56:51 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/08 12:40:24 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* _brain;
public:
    Dog();
	Dog(const Dog &ref);
    ~Dog();

	void	setIdea(int i, std::string idea);
	void	getIdeas();
	void	makeSound() const;
	Dog &operator=(Dog const &newDog);
};
