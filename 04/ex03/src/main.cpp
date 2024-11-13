/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:06:51 by gyvergni          #+#    #+#             */
/*   Updated: 2024/11/13 11:53:22 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	IMateriaSource*	src = new MateriaSource();
	Character *bob = new Character("Bob");
	Character *evildude = new Character("Evil dude");
	AMateria	*materia;

	src->learnMateria(new Ice());
	materia = src->createMateria("cure");
	materia = src->createMateria("ice");
	bob->equip(materia);
	bob->equip(src->createMateria("cure"));
	
	src->learnMateria(new Cure());
	bob->equip(src->createMateria("cure"));
	bob->equip(src->createMateria("ice"));
	materia = src->createMateria("ici");
	bob->equip(materia);
	materia = src->createMateria("cure");
	bob->equip(materia);
	evildude->equip(src->createMateria("ice"));
	materia = src->createMateria("summon chickenito");
	bob->use(1, *evildude);
	bob->use(2, *evildude);
	bob->use(5, *evildude);
	materia = bob->getSlot(1);
	bob->unequip(1);
	delete materia;
	bob->use(1, *evildude);
	*bob = *evildude;
	bob->use(1, *evildude);
	delete bob;
	delete evildude;
	delete src;
}
