/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:21:19 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/18 21:05:42 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "math.h"

//Constructors

Fixed::Fixed(void)
{
	this->_fpvalue = 0;
}

Fixed::Fixed(const int int_value)
{
	this->_fpvalue = (int_value << this->_nbits); 
}

Fixed::Fixed(const float float_value)
{
	this->_fpvalue = roundf(float_value * (1 << this->_nbits)); 
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

//Destructors

Fixed::~Fixed(void)
{
}

//Operators

Fixed &Fixed::operator=(const Fixed &src)
{
	this->_fpvalue = src.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>=(Fixed fixed) const
{
	return(this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(Fixed fixed) const
{
	return(this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator==(Fixed fixed) const
{
	return(this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(Fixed fixed) const
{
	return(this->toFloat() != fixed.toFloat());
}

///Arithmetic operators

float	Fixed::operator+(Fixed fixed)const
{
	return(this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed)const
{
	return(this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed)const
{
	return(this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed)const
{
	return(this->toFloat() / fixed.toFloat());
}

//Increment operators

Fixed Fixed::operator++()
{
	this->_fpvalue++;
	return(*this);
}

Fixed Fixed::operator--()
{
	this->_fpvalue--;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;

	++(this->_fpvalue);
	return(tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;

	--(this->_fpvalue);
	return(tmp);
}


//Member functions

int		Fixed::getRawBits(void) const
{
	return(this->_fpvalue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fpvalue = raw;
}

float Fixed::toFloat(void) const
{
	return ((float) this->_fpvalue / (float)(1 << this->_nbits));
}

int		Fixed::toInt(void) const
{
	return(this->_fpvalue >> this->_nbits);
}

//Arithmetic member functions

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.toFloat() <= fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.toFloat() <= fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.toFloat() >= fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.toFloat() >= fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

//Overload

std::ostream &operator<<(std::ostream &output, Fixed const &fixed)
{
	output << fixed.toFloat();
	return (output);
}