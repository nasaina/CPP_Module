/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:56:01 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/01 12:49:16 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITION_H
# define DEFINITION_H

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <limits.h>

typedef struct pseudo
{
	std::string	name;
} Pseudo;

typedef enum type
{
	CHAR = 0,
	INT = 1,
	DOUBLE = 2,
	FLOAT = 3,
	NONE = 4,
	OFLOAT = 5,
	ODOUBLE = 6,
	PSEUDO = 7,
	MAX = 8,
} type;

type	litteralType(std::string litteral);
void	printChar(char c);
void	printComma(float f, double d, int action);
void	printImpossible(int status);

#endif