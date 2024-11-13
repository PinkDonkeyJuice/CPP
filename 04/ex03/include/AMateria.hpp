/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:19:51 by gyvergni          #+#    #+#             */
/*   Updated: 2024/11/13 10:45:44 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "iostream"
#include "cstdlib"
#include "ICharacter.hpp"
#include <string>

class ICharacter;

class AMateria
{
	protected:
		AMateria();
		std::string _type;

	public:
		AMateria(const std::string &type);
		AMateria(const AMateria &ref);
		AMateria	&operator=(const AMateria &src);
		virtual ~AMateria();

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif