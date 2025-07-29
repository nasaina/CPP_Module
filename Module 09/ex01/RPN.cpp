/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:47:41 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/29 14:49:32 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	RPN::checkString(std::string const &first, std::string const &second, size_t status)
{
	int countDigit;
	int countOp;

	countDigit = 0;
	countOp = 0;
	for (size_t i = 0; i < first.length(); i++)
	{
		if (std::isdigit(first[i]))
			countDigit++;
		if (!std::isdigit(first[i]) && !isspace(first[i]))
			return (false);
	}
	for (size_t i = 0; i < second.length(); i++)
	{
		if (std::strchr("+-*/", second[i]))
			countOp++;
		if (!std::strchr("+-*/", second[i]) && !isspace(second[i]))
			return (false);
	}
	if (countDigit != countOp + 1 && !status)
		return (false);
	return (true);
}

bool	RPN::checkArgs(std::string const &av)
{
	map	tmp;
	size_t	i;
	size_t	j;
	size_t	last;
	size_t	status;

	i = 0;
	j = 0;
	last = 0;
	status = 0;
	if (!av.length())
		return (false);
	while (i < av.length())
	{
		i = j;
		while (!std::strchr("+*/-", av[i]) && i < av.length())
			i++;
		j = i;
		while ((std::strchr("+-*/", av[j]) || isspace(av[j])) && j < av.length())
			j++;
		tmp.insert(std::pair<std::string, std::string>(av.substr(last, i - last), av.substr(i, j - i)));
		last = j;
		std::string first = tmp.begin()->first;
		std::string second = tmp.begin()->second;
		if (!checkString(first, second, status))
			return (false);
		status++;
		tmp.clear();
	}
	return (true);
}

RPN	&RPN::operator=(RPN const &other)
{
	_operators = other._operators;
	_element = other._element;
	return (*this);
}

int	RPN::operation(int a, int b)
{
	if (_operators == "+")
		return (a + b);
	else if (_operators == "-")
		return (a - b);
	else if (_operators == "*")
		return (a * b);
	else if (_operators == "/")
	{
		if (b == 0)
			throw std::runtime_error("Error");
		return (a / b);
	}
	throw	std::runtime_error("Error");
	return (-1);
}

int	RPN::getElement(void) const
{
	return (_element.top());
}

void	RPN::makeOperation()
{
	int	a;
	int	b;

	a = _element.top();
	_element.pop();
	b = _element.top();
	_element.pop();
	_element.push(operation(b, a));
}

void	RPN::insertElement(std::string const &av)
{
	size_t	i;
	int		count;
	std::stack<std::string>	tmp;

	i = 0;
	count = 0;
	while (i < av.length())
	{
		while ((isspace(av[i]) || std::isdigit(av[i])) && i < av.length())
		{
			while (isspace(av[i]))
				i++;
			if (std::isdigit(av[i]))
			{
				tmp.push(av.substr(i, 1));
				_element.push(std::atoi(tmp.top().c_str()));
				tmp.pop();
				count++;
			}
			if (!std::isdigit(av[i]))
				break ;
			i++;
		}
		while (isspace(av[i]) && i < av.length())
			i++;
		_operators = av.substr(i, 1);
		if (_element.size() >= 2 && _operators[0])
			makeOperation();
		if (count <= 1)
			throw std::runtime_error("Error");
		i++;
	}
}

RPN::RPN(std::string const &av)
{
	_operators = "";
	if (checkArgs(av))
	{
		insertElement(av);
		std::cout << getElement() << std::endl;
	}
	else
		std::cerr << "Error" << std::endl;
}

RPN::~RPN()
{
}
