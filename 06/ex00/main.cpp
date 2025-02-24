/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:27:23 by gyvergni          #+#    #+#             */
/*   Updated: 2024/10/21 15:29:46 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char**argv)
{
	if (argc <= 1)
	{
		std::cout << "Need an argument!" << std::endl;
		return (1);
	}
	ScalarConverter *converter = new ScalarConverter(argv[1]);
	delete(converter);
	return (0);
}