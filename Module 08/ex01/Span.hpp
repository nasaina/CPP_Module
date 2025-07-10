/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:17:04 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/10 16:13:56 by nandrian         ###   ########.fr       */
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
		void	fillRange(int nb);
		~Span();
};

Span::Span(unsigned int N)
{
	_N = N;
}

int	abs(int &n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	Span::fillRange(int nb)
{
	int	count = _N - _numbers.size();

	while (count > 0)
	{
		addNumber(nb);
		count--;
	}
}

std::vector<int>	Span::getNumbers(void) const
{
	return (_numbers);
}

int		Span::shortestSpan(void) const
{
	int	_short;
	if (_numbers.size() <= 1)
		return (0);
	std::vector<int> v = _numbers;
	std::sort(v.begin(), v.end());
	_short = v[1] - *v.begin();
	for (size_t i = 1; i < v.size() - 1; i++)
	{
		if (v[i + 1] - v[i] < _short)
			_short = v[i + 1] - v[i];
	}
	return (_short);
}

int		Span::longestSpan(void) const
{
	if (_numbers.size() <= 1)
		return (0);
	std::vector<int> v = _numbers;
	std::sort(v.begin(), v.end());
	return (*(v.end() - 1) - *v.begin());
}

void	Span::addNumber(int nb)
{
	if (_numbers.size() >= _N)
		throw std::exception();
	_numbers.push_back(nb);
}

Span::~Span()
{
}

#endif