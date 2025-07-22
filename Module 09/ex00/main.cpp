/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:17:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/22 16:31:15 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	checkDay(int month, int day)
{
	if (day <= 0 || day > 31)
		return (false);
	if (!(month % 2) && month <= 7 && day > 30)
		return (false);
	else if (month % 2 && month > 7 && day > 30)
		return (false);
	return (true);
}

bool	checkFebruary(int year, int month, int day)
{
	if (month <= 0 || month > 12)
		return (false);
	if (month == 2)
	{
		if (day > 29)
			return (false);
		if (year % 4 != 0 && day == 29)
			return (false);
	}
	else
		return (checkDay(month, day));
	return (true);
}

bool	checkDate(int year, int month, int day)
{
	if (year < 2007 || (month < 0 || month > 31) || (day < 0 || day > 31))
		return (false);
	if (year == 2008)
	{
		if (month >= 8)
		{
			if (day < 8)
				return (false);
		}
		else
			return (false);
	}
	if (month <= 0 || month > 12)
		return (false);
	return (true);
}

bool	checkDigit(std::string const &content)
{
	std::string data = content;
	for (std::string::iterator i = data.begin(); i != data.end() && data.length(); i++)
	{
		if (!std::isdigit(*i))
			return (false);
	}
	return (true);
}

bool	checkFloat(std::string const &content)
{
	std::string data = content;
	for (std::string::iterator i = data.begin(); i != data.end() && data.length(); i++)
	{
		if (!std::isdigit(*i) && *i != '.')
			return (false);
	}
	return (true);
}

bool	dateCheck(std::string const &data)
{
	std::string	year;
	std::string	month;
	std::string	day;
	size_t		old;
	size_t		pos;

	pos = data.find('-', 0);
	if (pos != std::string::npos)
		year = data.substr(0, pos);
	old = pos + 1;
	pos = data.find('-', old);
	if (pos != std::string::npos)
		month = data.substr(old, pos - old);
	if (!year.length() || !month.length())
		return (false);
	old = pos + 1;
	pos = data.find(' ', old);
	day = data.substr(old, pos - old);
	if (!checkDigit(year) || !checkDigit(month) || !checkDigit(day))
		return (false);
	if (year.length() != 4 || month.length() != 2 || day.length() != 2)
		return (false);
	int	_year = std::atoi(year.c_str());
	int	_month = std::atoi(month.c_str());
	int	_day = std::atoi(day.c_str());
	if (!checkDate(_year, _month, _day) || !checkFebruary(_year, _month, _day))
		return (false);
	return (true);
}

#include <algorithm>

bool	checkSpace(std::string content)
{
	std::string::iterator i = content.begin();

	while (std::isspace(*i) && content.length() && i != content.end())
		i++;
	while ((std::isdigit(*i) || *i == '.' || *i == '-') && content.length() && i != content.end())
		i++;
	while (std::isspace(*i) && content.length() && i != content.end())
		i++;
	if (i != content.end())
		return (false);
	return (true);
}

bool	valueCheck(std::string const &second)
{
	std::string	data = second;
	int			count = 0;
	std::string::iterator	it = data.begin();
	
	if (!checkSpace(data))
	{
		std::cout << "Error : bad input => " << data;
		return (false);
	}
	data.erase(std::remove_if(data.begin(), data.end(), ::isspace), data.end());
	while (it != data.end() && data.length())
	{
		if (*it == '.')
			count++;
		it++;
	}
	if (count > 1)
	{
		std::cout << "Error : bad input => " << data;
		return (false);
	}
	it = data.begin();
	if (*it == '-')
	{
		std::cout << "Error : not a positive number" << std::endl;
		return (false);
	}
	while (it + 1 != data.end() && data.length())
		it++;
	if (!::isdigit(*it))
	{
		std::cout << "Error : bad input => " << data;
		return (false);
	}
	if (!checkFloat(data))
		return (false);
	return (true);
}

float	getValue(std::string const &content)
{
	float	value;

	if (!valueCheck(content))
		return (-1);
	value = std::atof(content.c_str());
	if (value < 0 || value > 1000)
	{
		std::cout << "Error : too large a number" << std::endl;
		return (-1);
	}
	return (value);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			BitcoinExchange	data;
			BitcoinExchange	input((std::string)av[1]);
			list			contain;
			
			std::cout << "---- data ----\n";
			contain = data.getElement();
			for (list::const_iterator it = contain.begin(); it != contain.end(); ++it) 
			{
				if (dateCheck(it->first))
					std::cout << it->first << std::endl;
			}
			std::cout << "\n---- input ----\n";
			list content = input.getElement();
			for (list::const_iterator it = content.begin(); it != content.end(); ++it) 
			{
				if (dateCheck(it->first))
					std::cout << it->first << " | ";
				if (getValue(it->second) != -1)
					std::cout << it->second << std::endl;
				else
					std::cout << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	return 0;
}
