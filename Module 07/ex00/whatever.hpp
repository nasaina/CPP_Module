/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:44:45 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/07 11:15:40 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T> void swap(T &A, T &B)
{
	T tmp;

	tmp = A;
	A = B;
	B = tmp;
}

template <typename T> T max(T &A, T &B)
{
	return (A > B ? A : B);
}

template <typename T> T min(T &A, T &B)
{
	return (A < B ? A : B);
}

#endif