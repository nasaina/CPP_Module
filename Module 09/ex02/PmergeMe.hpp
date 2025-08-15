/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 09:56:01 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/08 10:04:41 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <cstdlib>

typedef	std::vector<int>	vector;
typedef	std::vector<std::string>	vectorString;
typedef	std::deque<int>		deque;

class PmergeMe
{
	private:
		vector		_before;
		vector		_vElement;
		deque		_dElement;
		bool		checkArgs(std::string const &av);
		bool		insertElement(vectorString const &av);
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe	&operator=(const PmergeMe &other);
	public:
		PmergeMe(vectorString const	&av);
		vector	getVElement(void) const;
		deque	getDElement(void) const;
		~PmergeMe();
};

bool	PmergeMe::checkArgs(std::string const &av)
{
	for (size_t i = 0; i < av.length(); i++)
	{
		if (!std::isdigit(av[i]))
			return (false);
	}
	return (true);
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

bool	PmergeMe::insertElement(vectorString const &av)
{
	for (vectorString::const_iterator it = av.begin(); it != av.end(); it++)
	{
		if (!checkArgs(*it))
			return (false);
		_vElement.push_back(std::atoi(it->c_str()));
		_before.push_back(std::atoi(it->c_str()));
		_dElement.push_back(std::atoi(it->c_str()));
	}
	return (true);
}

PmergeMe::PmergeMe(vectorString	const &av)
{
	if (!insertElement(av))
		throw std::runtime_error("Error");
	for (vector::const_iterator it = _before.begin(); it != _before.end(); it++)
		std::cout << *it << " ";
	std::cout << "\a" << std::endl;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	_vElement = other.getVElement();

	return (*this);
}

vector	PmergeMe::getVElement(void) const
{
	return (_vElement);
}

deque	PmergeMe::getDElement(void) const
{
	return (_dElement);
}

PmergeMe::~PmergeMe()
{
}

#endif