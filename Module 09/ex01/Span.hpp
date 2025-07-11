/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:17:04 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/11 12:26:22 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <bits/stdc++.h>
# include <stdexcept>

class Span
{
	private:
		unsigned int				_N;
		std::vector<int>			_numbers;
	public:
		Span(unsigned int N);
		void	addNumber(int nb);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
		std::vector<int>	getNumbers(void) const;
		void	fillRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		~Span();
};

#endif