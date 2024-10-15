/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:15:40 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/10/15 15:21:35 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

class Contact
{
	private:
		int	index;
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;

		std::string _printLen(std::string str) const;
		std::string _getInput(std::string str) const;

	public:
		Contact();
		~Contact();
		void	init(void);
		void	setIndex(int i);
		int		getIndex();
		void	disp_contact(void);
		void	disp_info(void);
};

#endif