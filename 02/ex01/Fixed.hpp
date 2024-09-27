/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:31:20 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/18 20:20:04 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int					_fpvalue;
		static const int	_nbits = 8;

	public:
		Fixed(void);
		Fixed(const int int_value);
		Fixed(const float float_value);
		Fixed(const Fixed &copy);

		~Fixed(void);

		Fixed &operator=(const Fixed &src);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &output, Fixed const &fixed);

#endif
