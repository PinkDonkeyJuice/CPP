/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:51:21 by gyvergni          #+#    #+#             */
/*   Updated: 2024/11/12 17:20:09 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("undefined")
{
	std::cout << "default constructor for AMateria called" << std::endl;
}

AMateria::AMateria(const std::string &type) : _type(type)
{
	std::cout << "AMateria constructor called of type " << type << std::endl;
}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria	&AMateria::operator =(const AMateria &src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;
}

std::string const	&AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	(void) target;
}