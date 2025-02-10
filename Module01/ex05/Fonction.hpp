/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fonction.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:21:05 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/10 11:30:15 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONCTION_HPP
# define FONCTION_HPP

# include <iostream>
# include "Harl.hpp"

typedef struct s_Function
{
	std::string	Name;
	void	(Harl::*functions)(void);
}	Function;

#endif