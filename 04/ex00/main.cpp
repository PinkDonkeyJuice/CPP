/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:06:29 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/13 10:25:26 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* animal = new Animal();
const Animal* ruffus = new Dog();
const Animal* mouchette = new Cat();

const WrongAnimal* wronganimal = new WrongAnimal();
const WrongAnimal* wrongcat = new WrongCat();

std::cout << ruffus->getType() << " " << std::endl;
std::cout << mouchette->getType() << " " << std::endl;
ruffus->makeSound(); //will output the cat sound!
mouchette->makeSound();
animal->makeSound();

std::cout << "Now the wrong cat: " << std::endl;
wrongcat->makeSound();
wronganimal->makeSound();

delete ruffus, delete mouchette, delete animal, delete wronganimal, delete wrongcat;
return 0;
}