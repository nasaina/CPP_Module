/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:18:29 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/11 12:50:23 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
{
	_N = N;
}

void	Span::fillRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) + std::distance(_numbers.begin(), _numbers.end()) > _N)
		throw std::exception();
	_numbers.insert(_numbers.end(), begin, end);
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
