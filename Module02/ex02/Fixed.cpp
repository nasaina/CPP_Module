/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:37:51 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/25 15:48:30 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed	Fixed::max(Fixed &other1, Fixed &other2)
{
	if (other1 > other2)
		return (other1);
	return (other2);
}

Fixed	Fixed::min(Fixed &other1, Fixed &other2)
{
	if (other1 < other2)
		return (other1);
	return (other2);
}

Fixed	Fixed::max(const Fixed &other1, const Fixed &other2)
{
	if (other1 > other2)
		return (other1);
	return (other2);
}

Fixed	Fixed::min(const Fixed &other1, const Fixed &other2)
{
	if (other1 < other2)
		return (other1);
	return (other2);
}

Fixed::Fixed(void)
{
	_value = 0;
	return ;
}

int	Fixed::getValue(void) const
{
	return (this->_value);
}

int	Fixed::getBits(void) const
{
	return (this->_bits);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &other)
{
	os << (float)other.getValue() / (float)pow(2, other.getBits());
	return (os);
}

Fixed::Fixed(int const raw)
{
	this->_value = (int)roundf(pow(2, _bits) * raw);
	return ;
}

Fixed::Fixed(float const raw)
{
	this->_value = (float)roundf(pow(2, _bits) * raw);
	return ;
}

int	Fixed::toInt(void) const
{
	int	result;

	result = this->_value / pow(2, 8);
	return (result);
}

float	Fixed::toFloat(void) const
{
	float	result;

	result = (float)this->_value / (float)pow(2, 8);
	return (result);
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	this->_value = other._value;
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;
	float	tmp;

	tmp = this->toFloat() + other.toFloat();
	result._value = tmp * roundf(pow(2, other.getBits()));
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;
	float	tmp;

	tmp = this->toFloat() - other.toFloat();
	result._value = tmp * roundf(pow(2, other.getBits()));
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	result;
	float	tmp;

	tmp = this->toFloat() * other.toFloat();
	result._value = tmp * roundf(pow(2, other.getBits()));
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	result;
	float	tmp;

	tmp = this->toFloat() / other.toFloat();
	result._value = tmp * roundf(pow(2, other.getBits()));
	return (result);
}

bool	Fixed::operator<(const Fixed &other) const
{
	if (this->_value < other._value)
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed &other) const
{
	if (this->_value > other._value)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	if (this->_value <= other._value)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	if (this->_value >= other._value)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &other) const
{
	if (this->_value == other._value)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	if (this->_value != other._value)
		return (true);
	return (false);
}

Fixed	&Fixed::operator++(void)
{
	++_value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp;
	tmp = *this;
	++_value;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	--_value;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp;
	tmp = *this;
	--_value;
	return (tmp);
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed()
{
	return ;
}
