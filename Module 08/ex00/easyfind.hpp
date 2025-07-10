/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:44:45 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/10 14:05:35 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <bits/stdc++.h>
# include <iostream>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T A, int index)
{
	typename T::iterator it = std::find(A.begin(), A.end(), index);
	if (it == A.end())
		throw std::runtime_error("Occurence not found");
	return (it);
};

#endif