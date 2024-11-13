/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:06:29 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/13 11:57:59 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *pets[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			pets[i] = new Dog();
		else
			pets[i] = new Cat();
	};
	
	for (int i = 0; i < 10; i++)
	{
		pets[i]->makeSound();
	}
	for (int i = 0; i < 10; i++)
	{
		delete(pets[i]);
	}
	std::cout << std::endl;
	//Deep copy test
	Cat *Tom = new Cat();
	
	Tom->setIdea(0, "I want to watch the world burn");
	Tom->getIdeas();

	Cat Jerry = Cat(*Tom);

	Jerry.setIdea(1, "I like sausages");
	Jerry.getIdeas();
	Tom->getIdeas();
	std::cout << "assignement operator" << std::endl;
	*Tom = Jerry;
	Tom->getIdeas();

	//Dog
	std::cout << std::endl;
	Dog *Ruffus = new Dog();
	
	Ruffus->setIdea(0, "I want to watch the world burn");
	Ruffus->getIdeas();

	Dog JeanMich = Dog(*Ruffus);

	JeanMich.setIdea(1, "I like sausages");
	JeanMich.getIdeas();
	Ruffus->getIdeas();
	std::cout << "assignement operator" << std::endl;
	*Ruffus = JeanMich;
	Ruffus->getIdeas();
	delete Ruffus, delete Tom;
}
