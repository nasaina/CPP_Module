/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:17:04 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/09 09:07:13 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <stdexcept>

template <typename T> class Array
{
	private:
		T				*_element;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		T				&operator[](unsigned int n);

		T				*getElement(void) const;
		unsigned int	size(void) const;
		class outOfBound : public std::exception
		{
			virtual const char *what() const throw();
		};
		void	setElement(T other, unsigned int index);
		~Array();
};

template<typename T>
void	Array<T>::setElement(T other, unsigned int index)
{
	if (index >= this->size())
		throw outOfBound();
	_element[index] = other;
}

template<typename T>
Array<T>::Array()
{
	_element = new T[0];
	_size = 0;
}

template<typename T>
T	&Array<T>::operator[](unsigned int n)
{
	if (n >= _size)
		throw outOfBound();
	return (_element[n]);
}

template<typename T>
const char *Array<T>::outOfBound::what() const throw()
{
	return ((const char *)"Your index is out of bound.");
}

template<typename T>
Array<T>::Array(const Array<T> &other)
{
	_element = new T[other.size()];
	for (unsigned int i = 0; i < other.size(); i++)
		_element[i] = other.getElement()[i];
	_size = other.size();
}

template<typename T>
T	*Array<T>::getElement(void) const
{
	return (_element);
}

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return (_size);
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	_element = new T[n];
	_size = n;
	for (unsigned int i = 0; i < _size; i++)
		_element[i] = 0;
}

template<typename T>
Array<T>::~Array()
{
	delete [] _element;
}

#endif