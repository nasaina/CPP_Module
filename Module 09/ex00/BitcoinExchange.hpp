/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:24:47 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/14 11:48:17 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <utility>
# include <list>
# include <sstream>
# include <stdexcept>
# include <cstdlib>

typedef std::list<std::pair<std::string, std::string> > list;

class BitcoinExchange
{
	private:
		list	_element;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		list	&getElement(void) const;
		~BitcoinExchange();
};

list	&BitcoinExchange::getElement(void) const
{
	return ((list &)_element);
}

BitcoinExchange::BitcoinExchange()
{
	std::fstream	fs;
	std::string		date;
	std::string		value;
	std::string		filename = "data.csv";

	fs.open(filename.c_str(), std::ios::in);
	if (!fs)
		throw std::runtime_error("Error: could not open file.");
	std::string line;
    while (std::getline(fs, line))
	{
        std::stringstream	ss(line);
        std::string			first;
        std::string			second;

        if (std::getline(ss, first, ',') && std::getline(ss, second))
			_element.push_back(std::make_pair(first, second));
    }
	fs.close();
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::fstream	fs;
	std::string		date;
	std::string		value;

	fs.open(filename.c_str(), std::ios::in);
	if (!fs)
		throw std::runtime_error("Error: could not open file.");
	std::string line;
    while (std::getline(fs, line))
	{
        std::stringstream	ss(line);
        std::string			first;
        std::string			second;

		if (std::getline(ss, first, '|'))
		{
			if (std::getline(ss, second))
				_element.push_back(std::make_pair(first, second));
			else
				_element.push_back(std::make_pair(first, ""));
		}
    }
	fs.close();
}

BitcoinExchange::~BitcoinExchange()
{
}

#endif