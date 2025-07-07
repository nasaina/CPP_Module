/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Element.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:57:33 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/04 11:27:01 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Element.hpp"

Element::Element()
{
	_type = NONE;
}

Element::Element(const Element &other)
{
	*this = other;	
}

Element	&Element::operator=(const Element &other)
{
	this->_c = other.getChar();
	this->_i = other.getInt();
	this->_f = other.getFloat();
	this->_d = other.getDouble();
	this->_type = other.getType();
	return (*this);
}

type	Element::getType(void) const
{
	return (_type);
}

char	Element::getChar(void) const
{
	return (_c);
}
int		Element::getInt(void) const
{
	return (_i);
}
float	Element::getFloat(void) const
{
	return (_f);
}
double	Element::getDouble(void) const
{
	return (_d);
}

Element::Element(std::string litteral)
{
	_type = litteralType(litteral);
	if (_type == CHAR)
	{
		_c = static_cast<char>(litteral[0]);
		_i = static_cast<int>(_c);
		_f = static_cast<float>(_c);
		_d = static_cast<double>(_c);
	}
	else if (_type == INT)
	{
		_i = std::atoi(litteral.c_str());
		_c = static_cast<char>(_i);
		_f = static_cast<float>(_i);
		_d = static_cast<double>(_i);
	}
	else if (_type == FLOAT || _type == OFLOAT || _type == MAX)
	{
		_f = std::atof(litteral.c_str());
		_c = static_cast<char>(_f);
		_i = static_cast<int>(_f);
		_d = static_cast<double>(_f);
	}
	else if (_type == DOUBLE || _type == ODOUBLE)
	{
		_d = std::atof(litteral.c_str());
		_c = static_cast<char>(_d);
		_i = static_cast<int>(_d);
		_f = static_cast<float>(_d);
	}
	else if (_type == PSEUDO)
	{
		_d = std::atof(litteral.c_str());
		_f = _d;
	}
}

void	Element::printElement(void)
{
	if (_type == NONE)
	{
		printImpossible(1);
		return ;
	}
	else if (_type == PSEUDO)
	{
		printImpossible(0);
		std::cout << "float : " << _d << "f" << std::endl;
		std::cout << "double : " << _f << std::endl;
		return ;
	}
	if (_type == MAX)
		printImpossible(0);
	else
	{
		printChar(_c);
		std::cout << "int : " << _i << std::endl;
	}
	if (_type == ODOUBLE || _type == OFLOAT || _type == INT)
		printComma(_f, _d, 1);
	else
		printComma(_f, _d, 0);
}

Element::~Element()
{
}