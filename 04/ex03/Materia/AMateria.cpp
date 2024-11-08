/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:51:21 by gyvergni          #+#    #+#             */
/*   Updated: 2024/11/08 16:27:04 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "default constructor for AMateria called" << std::endl;
}

AMateria::AMateria(const std::string type) : _type(type)
{
	std::cout << "AMateria constructor called of type " << type << std::endl;
}
