/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:29:33 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/02/03 11:11:37 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ColorsFt.hpp"
#include "Span.hpp"

Span::Span(unsigned int N) : size(N)
{
	std::cout << PINK << "[Span]" << GREEN << " - Create vector with " << N << " elements" << RESET << std::endl;
	if (N <= 0)
		throw std::logic_error("N cannot be less than 0");

	_numbers.reserve(N);
}

Span::~Span() { std::cout << PINK << "[Span]" << RED << " - Destructor" << RESET << std::endl; }

Span::Span() { std::cout << PINK << "[Span]" << GREEN << " - Constructor without parameter" << RESET << std::endl; }

Span::Span(const Span &tmp)
{
	std::cout << PINK << "[Span]" << CYAN << " - Copy constructor" << RESET << std::endl;
	*this = tmp;
}

int Span::shortestSpan() const
{
	if (_numbers.size() <= 1)
		throw std::logic_error("Not enough numbers to find Span");

	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int minSpan = INT_MAX;
	for (size_t i = 1; i < sortedNumbers.size(); ++i)
		minSpan = std::min(minSpan, sortedNumbers[i] - sortedNumbers[i - 1]);

	return minSpan;
}

int Span::longestSpan() const
{
	if (_numbers.size() <= 1)
		throw std::logic_error("Not enough numbers to find span");

	return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}

Span &Span::operator=(const Span &tmp)
{
	std::cout << PINK << "[Span]" << YELLOW << " - Assignation operator" << RESET << std::endl;

	if (this != &tmp)
		this->_numbers = tmp._numbers;
	return *this;
}

void Span::addNumber(int n)
{
	if (_numbers.size() == _numbers.capacity())
		throw std::out_of_range("Exceeded maximum capacity");
	_numbers.push_back(n);
}

void Span::printValues() const
{
	for (size_t i = 0; i < _numbers.size(); ++i)
	{
		std::cout << _numbers[i];
		if (i < _numbers.size() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

void Span::printSort() const
{
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	for (size_t i = 0; i < sortedNumbers.size(); ++i)
	{
		std::cout << sortedNumbers[i];
		if (i < sortedNumbers.size() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

unsigned int Span::getSize() const { return _numbers.size(); }
unsigned int Span::getCapacity() const { return _numbers.capacity(); }

//=========================================================================

// std::ostream &operator<<(std::ostream &out, const Span &tmp)
// {
// 	out << "Elements: \n";
// 	(void)tmp;

// 	std::cout << tmp[1];
// 	// for (size_t i = 0; i < tmp.size(); ++i)
// 	// {
// 	// 	out << tmp[i];
// 	// 	if (i < tmp.size() - 1)
// 	// 	{
// 	// 		out << ", ";
// 	// 	}
// 	// }
// 	return out;
// }

//    int &operator[](size_t index) {
//         if (index >= _numbers.size()) {
//             // Aquí podrías lanzar una excepción si lo prefieres, por ejemplo, std::out_of_range
//             std::cerr << "Error: Index out of range." << std::endl;
//             // Puedes lanzar una excepción std::out_of_range aquí si lo prefieres
//             // throw std::out_of_range("Index out of range");
//         }
//         return _numbers[index];
//     }
