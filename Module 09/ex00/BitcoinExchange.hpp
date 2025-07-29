/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:24:47 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/29 08:15:52 by nandrian         ###   ########.fr       */
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

#endif