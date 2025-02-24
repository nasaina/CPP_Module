/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:11:49 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/24 16:25:50 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
# include <math.h>

class Fixed
{
private:
	int					_value;
	static const int	_bits = 8;
public:
	Fixed(void);
	Fixed(int const raw);
	Fixed(float const raw);
	Fixed(const Fixed &other);
	Fixed	&operator=(const Fixed &other);
	~Fixed();
	float toFloat( void ) const;
	int toInt( void ) const;
	int	getValue(void) const;
	int	getBits(void) const;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &other);

#endif