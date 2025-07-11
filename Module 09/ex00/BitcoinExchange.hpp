/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:24:47 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/11 16:45:16 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <utility>
# include <list>
# include <sstream>

typedef std::list<std::pair<std::string, std::string> > list;

class BitcoinExchange
{
	private:
		list	_element;
	public:
		BitcoinExchange();
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
		return ;

	std::string line;
    while (std::getline(fs, line))
	{
        std::stringstream ss(line);
        std::string firstColumn;
        std::string secondColumn;

        if (std::getline(ss, firstColumn, ',') && std::getline(ss, secondColumn)) 
			_element.push_back(std::make_pair(firstColumn, secondColumn));
    }
}

BitcoinExchange::~BitcoinExchange()
{
}

#endif