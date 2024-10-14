/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:41:04 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/10/14 20:41:08 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string _target;

public:
    PresidentialPardonForm(const std::string target);
    PresidentialPardonForm(const  PresidentialPardonForm &copy);
    ~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const  PresidentialPardonForm &src);
	std::string getTarget() const;
	void	execute(Bureaucrat& executor) const;
};

std::ostream &	operator<<(std::ostream & o, PresidentialPardonForm const &rSym);