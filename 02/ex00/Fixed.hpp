/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:31:20 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/18 18:22:20 by pinkdonkeyj      ###   ########.fr       */
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
		Fixed(const Fixed &copy);

		~Fixed(void);

		Fixed &operator=(const Fixed &src);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
