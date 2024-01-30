/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:49:02 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/30 23:04:45 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "ColorsFt.hpp"

template <typename T>
class Array
{
private:
	T *_items;
	size_t _size;

public:
	Array();
	Array(size_t);
	Array(const Array &);
	Array<T> &operator=(const Array &);
	T &operator[](size_t);
	// T &front() const;
	// T &back() const;
	~Array();
	void copy(const T *source, T *destination, size_t size);
	size_t size();
	bool empty();
	void clear();

	class OutOfBoundsException : public std::exception
	{
	public:
		virtual const char *what() const throw() { return ERROR "[ Index is out of bounds ]" RESET; }
	} e_out;
};

template <typename T>
Array<T>::Array() : _items(nullptr), _size(0)
{
	std::cout << PINK << "[ARRAY]" << GREEN << " - Constructor without parameter" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(const Array &rhs)
{
	std::cout << PINK << "[ARRAY]" << CYAN << " - Copy constructor" << RESET << std::endl;
	*this = rhs;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << PINK << "[ARRAY]" << RED << " - Destructor" << RESET << std::endl;
	delete[] _items;
}

template <typename T>
Array<T>::Array(size_t i) : _items(nullptr), _size(i)
{
	std::cout << PINK << "[ARRAY]" << GREEN << " - Constructor with numer items" << RESET << std::endl;
	_items = new T[i]();
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &tmp)
{
	std::cout << PINK << "[ARRAY]" << YELLOW << " - Assignation operator" << RESET << std::endl;
	if (this != &tmp)
	{
		delete[] _items;
		_size = tmp._size;
		_items = new T[_size];
		std::copy(tmp._items, tmp._items + _size, _items);
	}
	return *this;
}

template <typename T>
size_t Array<T>::size() { return _size; }

template <typename T>
T &Array<T>::operator[](size_t i)
{
	if (i >= _size)
		throw e_out;
	return _items[i];
}

// BONUS

// template <typename T>
// Array<T>::Array(const T arr[], size_t size) : _items(new T[size]), _size(size)
// {
// 	std::cout << PINK << "[ARRAY]" << GREEN << " - Constructor with array" << RESET << std::endl;
// 	for (size_t i = 0; i < size; ++i)
// 	{
// 		_items[i] = arr[i];
// 	}
// }

template <typename T>
bool Array<T>::empty() { return this->_size == 0; }

template <typename T>
void Array<T>::clear()
{
	delete[] _items;
	_items = nullptr;
	_size = 0;
}

#endif

// Método resize(size_t new_size) (void resize(size_t new_size)):
//     Este método cambia el tamaño del array, ajustando la asignación de memoria según el nuevo tamaño.

// Método front() (T &front() const):
//     Este método devuelve una referencia al primer elemento del array.

// Método back() (T &back() const):
//     Este método devuelve una referencia al último elemento del array.

// Método begin() y end() para iteración (T *begin(), T *end(), const T *begin() const, const T *end() const):

// arr.push(...items) – agrega ítems al final,
// arr.pop() – extrae un ítem del final,
// arr.shift() – extrae un ítem del inicio,
// arr.unshift(...items) – agrega ítems al principio.
