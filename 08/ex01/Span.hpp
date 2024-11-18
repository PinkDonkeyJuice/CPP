/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:31:58 by gyvergni          #+#    #+#             */
/*   Updated: 2024/11/18 11:31:38 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _v;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &ref);
		~Span();
		
		Span &operator=(const Span &ref);
		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();

		void	addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end);

		class VectorFullException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class ToofewElementsException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif