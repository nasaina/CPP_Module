/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:17:55 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/11 12:19:55 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T> MutantStack<T>::MutantStack()
{
}

template <typename T>
typename std::deque<T>::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename std::deque<T>::iterator	MutantStack<T>::end()
{
	return (this->c.end());
}

template<typename T> MutantStack<T>::~MutantStack()
{
}
