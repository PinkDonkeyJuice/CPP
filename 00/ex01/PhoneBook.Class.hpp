/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:48:33 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/08/07 12:38:25 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <iomanip>
#include "Contact.Class.hpp"

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