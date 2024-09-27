/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:27:56 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/25 19:02:23 by pinkdonkeyj      ###   ########.fr       */
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

	Brain &operator=(Brain const &newBrain);
};
