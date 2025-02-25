/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:27:58 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/25 13:15:29 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const raw)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = raw * (pow(2, 8));
	return ;
}

Fixed::Fixed(float const raw)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = (int)roundf(raw * (pow(2, 8)));
	return ;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
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

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = other._value;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &other)
{
	os << (float) other.getValue() / (float)pow(2, other.getBits());
	return (os);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

float Fixed::toFloat( void ) const
{
	float	result;

	result = (float)_value / (float)pow(2, _bits);
	return (result);
}

int Fixed::toInt( void ) const
{
	int	result;

	result = (int)_value / (int)pow(2, _bits);

	return (result);
}
