/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:31:20 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/18 21:05:15 by pinkdonkeyj      ###   ########.fr       */
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

		Fixed &operator=(const Fixed &fixed);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed &min(Fixed &fixed1, Fixed &fixed2);
		static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
		static Fixed &max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);

		bool operator>(Fixed fixed) const;
		bool operator<(Fixed fixed) const;
		bool operator>=(Fixed fixed) const;
		bool operator<=(Fixed fixed) const;
		bool operator==(Fixed fixed) const;
		bool operator!=(Fixed fixed) const;
		
		float operator+(Fixed fixed)const;
		float operator-(Fixed fixed)const;
		float operator*(Fixed fixed)const;
		float operator/(Fixed fixed)const;
		
		Fixed operator++();
		Fixed operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		
};

std::ostream &operator<<(std::ostream &output, Fixed const &fixed);

#endif
