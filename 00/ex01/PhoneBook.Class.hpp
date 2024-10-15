/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:48:33 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/10/15 13:27:24 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <iomanip>
#include "Contact.Class.hpp"
#include <cstdlib>
#include <iomanip>

class PhoneBook
{
private:
	Contact _contacts[8];
	int		_readinput(void) const;

public:
	PhoneBook();
	~PhoneBook();
	void	addContact(void);
	void	printContacts(void);
	void	search(void);
	void	welcome(void) const;
};

#endif