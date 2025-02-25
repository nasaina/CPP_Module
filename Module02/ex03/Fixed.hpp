/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:21:45 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/25 15:50:12 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					_value;
	static const int	_bits = 8;
public:
	Fixed(void);
	Fixed(int const raw);
	Fixed(float const raw);
	int		toInt(void) const;
	float	toFloat(void) const;
	int		getValue(void) const;
	int		getBits(void) const;

	Fixed(const Fixed &other);
	Fixed	&operator=(const Fixed &other);
	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;

	bool	operator<(const Fixed &other) const;
	bool	operator>(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;

	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);

	static Fixed	max(Fixed &other1, Fixed &other2);
	static Fixed	max(const Fixed &other1, const Fixed &other2);
	static Fixed	min(Fixed &other1, Fixed &other2);
	static Fixed	min(const Fixed &other1, const Fixed &other2);
	~Fixed();
};

#endif