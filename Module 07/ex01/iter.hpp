/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:17:04 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/09 07:46:16 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T> void iter(const T *A, int B, void (*F)(T &))
{
	T *D = const_cast<T *>(A);
	for (int i = 0; i < B; i++)
		F(D[i]);
}

#endif