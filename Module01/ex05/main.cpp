/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:34:40 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/10 11:19:45 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main(void)
{
	void	(Harl::* complainCaller)(std::string) = &Harl::complain;
	Harl	harley;

	(harley.*complainCaller) ("debug");
	(harley.*complainCaller) ("warning");
	(harley.*complainCaller) ("info");
	(harley.*complainCaller) ("error");
}
