/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:56:51 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/27 10:52:01 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
private:

public:
    Dog();
	Dog(const Dog &ref);
    ~Dog();

	void	makeSound() const;
	Dog &operator=(Dog const &newDog);
};