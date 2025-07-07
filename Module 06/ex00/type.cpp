/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:02:29 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/01 12:51:37 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool DigitCheck(std::string str)
{
	size_t	i;

	i = 0;
	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

type	floatType(std::string litteral)
{
	std::size_t	i = 0;

	while (litteral[i] == '-' || litteral[i] == '+')
		i++;
	while (std::isdigit(litteral[i]))
		i++;
	if (litteral[i] == '.')
	{
		i++;
		if (!std::isdigit(litteral[i]))
			return (NONE);
		if (litteral[i] == '0' && (i + 1 >= litteral.length() || litteral[i + 1] == 'f'))
		{
			if (i + 1 >= litteral.length())
				return (ODOUBLE);
			else if (litteral[i + 1] == 'f')
				return (OFLOAT);
		}
		while (std::isdigit(litteral[i]))
			i++;
		if (litteral[i] != 'f' && i < litteral.length())
			return (NONE);
		if (litteral[i] == 'f')
			return (FLOAT);
		else if (i >= litteral.length())
			return (DOUBLE);
	}
	if (i >= litteral.length())
		return (INT);
	return (NONE);
}

type	count(std::string litteral)
{
	std::size_t	i = 0;
	int			countF = 0;
	int			countPoint = 0;
	int			countSign = 0;

	for (i = i; i < litteral.length(); i++)
	{
		if (litteral[i] == '.')
			countPoint++;
		if (litteral[i] == 'f')
			countF++;
		if (litteral[i] == '-' || litteral[i] == '+')
			countSign++;
	}
	if (countF > 1 || countPoint > 1 || countSign > 1)
		return (NONE);
	return (floatType(litteral));
}

void	printImpossible(int status)
{
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;
	if (status == 1)
	{
		std::cout << "float : impossible" << std::endl;
		std::cout << "double : impossible" << std::endl;
	}
}

type	getType(std::string litteral)
{
	if (std::atof(litteral.c_str()) > INT_MAX || std::atof(litteral.c_str()) < INT_MIN)
		return (MAX);
	if (DigitCheck(litteral))
		return (INT);
	if (litteral.length() == 1 && std::isprint(litteral[0]))
		return (CHAR);
	return (count(litteral));
}

void	printChar(char c)
{
	if (std::isprint(c))
		std::cout << "char : " << c << std::endl;
	else if (!std::isprint(c))
		std::cout << "char : Non displayable" << std::endl;
}

void	printComma(float f, double d, int action)
{
	if (action == 0)
	{
		std::cout << "float : " << f << "f" << std::endl;
		std::cout << "double : " << d << std::endl;
	}
	else if (action == 1)
	{
		std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;
	}
}

type	litteralType(std::string litteral)
{
	Pseudo	pseudo[6] = {
		"-inff",
		"+inff",
		"nanf",
		"-inf",
		"+inf",
		"nan",
	};
	for (int i = 0; i < 6; i++)
	{
		if (litteral == pseudo[i].name)
			return (PSEUDO);
	}
	return (getType(litteral));
}
