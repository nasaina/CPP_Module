/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:17:04 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/11 12:21:23 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stdexcept>
# include <stack>
# include <bits/stdc++.h>

template <typename T> 
class MutantStack : public std::stack<T>
{
	private:

	public:
		typedef	typename std::deque<T>::iterator iterator;
		MutantStack();
		typename std::deque<T>::iterator	begin();
		typename std::deque<T>::iterator	end();
		~MutantStack();
};

#include "MutantStack.tpp"

#endif
