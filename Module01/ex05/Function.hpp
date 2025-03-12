/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Function.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:21:05 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/10 11:43:49 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_HPP
# define FUNCTION_HPP

# include <iostream>
# include "Harl.hpp"

typedef struct sFunction
{
	std::string	Name;
	void	(Harl::*functions)(void);
}	Function;

#endif