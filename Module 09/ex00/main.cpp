/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:17:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/11 16:40:32 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac == 2)
	{
		BitcoinExchange	data;
		list			contain;
		
		contain = data.getElement();
		for (list::const_iterator it = contain.begin(); it != contain.end(); ++it) 
		{
			std::cout << it->first << " : " << it->second << std::endl;
		}
	}
	return 0;
}
