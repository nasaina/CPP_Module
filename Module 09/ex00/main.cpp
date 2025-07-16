/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:17:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/16 14:11:14 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	checkDay(int month, int day)
{
	if (!(month % 2) && month <= 7 && day > 30)
		return (false);
	else if (month % 2 && month > 7 && day > 30)
		return (false);
	return (true);
}

bool	checkFebruary(int year, int month, int day)
{
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
	day = data.substr(pos + 1, data.length() - 12);
	int	_year = std::atoi(year.c_str());
	int	_month = std::atoi(month.c_str());
	int	_day = std::atoi(day.c_str());
	if (!checkDate(_year, _month, _day) || !checkFebruary(_year, _month, _day))
		return (false);
	return (true);
}

// bool	lineCheck(list content)
// {
// 	for (list::const_iterator it = content.begin(); it != content.end(); ++it) 
// 	{
		
// 	}
// }

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
					std::cout << it->first << std::endl;
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
