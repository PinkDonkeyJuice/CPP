/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:27:56 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/08 14:04:44 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Brain
{
private:
	std::string _ideas[100];

public:
    Brain();
	Brain(const Brain &ref);
    ~Brain();

	std::string	getIdea(int i);
	void	brain_setIdea(int i, std::string idea);
	Brain &operator=(Brain const &newBrain);
};
