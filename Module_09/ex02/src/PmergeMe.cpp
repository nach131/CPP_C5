/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:51:10 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/02/14 13:37:26 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string ori) : _sorted(false), _ori(ori)
{
	std::istringstream iss(ori);
	while (iss >> _token)
	{
		if (isValidToken(_token))
		{
			long value = std::strtol(_token.c_str(), NULL, 10);
			if (value >= INT_MAX || value <= INT_MIN)
				throw std::runtime_error("Error: Some value is larger or smaller than integer");
			// else
			// {
			// 	// Esto ira fuera
			// 	// _vec.push_back(static_cast<int>(value));
			// 	// _lst.push_back(static_cast<int>(value));
			// }
		}
		else
			throw std::runtime_error("Error: Some value is not an integer.");
	}
	print();
	startVec();
	print();
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
		// this->_stack = other._stack;
		// TODO
		// std::copy(rhs._list.begin(), rhs._list.end(), std::back_inserter(this->_list));
		// ;
		return *this;
}

bool PmergeMe::isValidToken(const std::string &token)
{
	for (std::string::const_iterator it = token.begin(); it != token.end(); ++it)
	{
		char c = *it;
		if (!(c >= '0' && c <= '9'))
			return false;
	}
	return true;
}

void PmergeMe::addToContainer(int type)
{
	std::istringstream iss(_ori);
	while (iss >> _token)
	{
		long value = std::strtol(_token.c_str(), NULL, 10);
		if (type == VEC)
			_vec.push_back(static_cast<int>(value));
		else if (type == LST)
			;
		// _lst.push_back(static_cast<int>(value));
	}
}

double PmergeMe::measureTimeMergeSort(int type)
{
	clock_t start = clock();
	addToContainer(type);

	// mergeSort(arr, 0, arr.size() - 1);

	clock_t end = clock();
	double duration = (double)(end - start) / CLOCKS_PER_SEC;
	return duration * 1000.0;
}

void PmergeMe::print()
{
	if (!_sorted)
		std::cout << "Before: ";
	else
		std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::startVec()
{
	std::cout << "Time to process a range of " << measureTimeMergeSort(VEC) << " us" << std::endl;
}
