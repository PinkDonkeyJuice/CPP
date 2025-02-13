/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:08:22 by gyvergni          #+#    #+#             */
/*   Updated: 2024/12/16 16:18:16 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

int	main()
{
	Span sp = Span(6);
	std::vector<int> vec;
	
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(1);
		sp.addNumber(18);
		sp.addNumber(9);
		sp.addNumber(11);
	
		std::cout << "handmade shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "handmade longest span: " << sp.longestSpan() << std::endl;
	
		srand((unsigned) time(NULL));
		sp = Span(10000);
		for (unsigned int i = 0; i < 10000; i++)
		{
			vec.push_back(rand());
		}
		sp.addNumbers(vec.begin(), vec.end());
		std::cout << "random shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "random longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
