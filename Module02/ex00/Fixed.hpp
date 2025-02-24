/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:16:33 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/24 15:11:59 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed	&operator=(const Fixed &other);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif