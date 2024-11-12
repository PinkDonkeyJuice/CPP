/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:06:51 by gyvergni          #+#    #+#             */
/*   Updated: 2024/11/12 17:29:53 by gyvergni         ###   ########.fr       */
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
	ICharacter *bob = new Character("Bob");
	ICharacter *evildude = new Character("Evil dude");
	AMateria	*materia;

	src->learnMateria(new Ice());
	materia = src->createMateria("cure");
	materia = src->createMateria("ice");
	bob->equip(materia);
	bob->equip(src->createMateria("cure"));
	
	src->learnMateria(new Cure());
	bob->equip(src->createMateria("cure"));
	bob->equip(src->createMateria("ice"));
	bob->equip(src->createMateria("cure"));
	bob->equip(src->createMateria("cure"));
	
	materia = src->createMateria("summon chickenito");
	bob->use(1, *evildude);
	bob->use(2, *evildude);
	bob->use(5, *evildude);
	bob->unequip(3);
	bob->use(3, *evildude);
	
	bob->use(1, *evildude);
	delete evildude;
	delete bob;
	delete src;
}
