/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:51:10 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/02/15 18:53:11 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string ori) : _timeVec(0), _timeLst(0), _ori(ori)
{
	std::istringstream iss(ori);
	while (iss >> _token)
	{
		if (isValidToken(_token))
		{
			long value = std::strtol(_token.c_str(), NULL, 10);
			if (value >= INT_MAX || value <= INT_MIN)
				throw std::runtime_error("Error: Some value is larger or smaller than integer.");
		}
		else
			throw std::runtime_error("Error: Some value is not an integer.");
	}
	std::cout << "Before: " << ori << std::endl;
	_timeVec = start(VEC);
	_timeLst = start(LST);
	print();
	// printList();
}

PmergeMe::~PmergeMe()
{
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::[..] : " << _timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _lst.size() << " elements with std::[..] : " << _timeLst << " us" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
	: _timeVec(other._timeVec), _timeLst(other._timeLst), _ori(other._ori), _vec(other._vec), _lst(other._lst) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_lst = other._lst;
		_vec = other._vec;
	}
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
			_lst.push_back(static_cast<int>(value));
	}
}

double PmergeMe::start(int type)
{
	clock_t start = clock();
	addToContainer(type);
	if (type == VEC)
		mergeSortVector(_vec, 0, _vec.size() - 1);
	else
		mergeSortList(_lst, _lst.begin(), _lst.end());

	clock_t end = clock();
	double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
	return duration;
}

void PmergeMe::print()
{
	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printList()
{
	for (std::list<int>::const_iterator it = _lst.begin(); it != _lst.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::mergeList(std::list<int>::iterator l, std::list<int>::iterator m, std::list<int>::iterator r)
{
	std::list<int> L(l, m);
	std::list<int> R(m, r);

	std::list<int>::iterator itL = L.begin();
	std::list<int>::iterator itR = R.begin();

	while (itL != L.end() && itR != R.end())
	{
		if (*itL <= *itR)
		{
			*l = *itL;
			++itL;
		}
		else
		{
			*l = *itR;
			++itR;
		}
		++l;
	}

	while (itL != L.end())
	{
		*l = *itL;
		++itL;
		++l;
	}

	while (itR != R.end())
	{
		*l = *itR;
		++itR;
		++l;
	}
}

void PmergeMe::mergeSortList(std::list<int> &arr, std::list<int>::iterator l, std::list<int>::iterator r)
{
	if (std::distance(l, r) > 1)
	{
		std::list<int>::iterator m = l;
		std::advance(m, std::distance(l, r) / 2);

		mergeSortList(arr, l, m);
		mergeSortList(arr, m, r);

		mergeList(l, m, r);
	}
}

void PmergeMe::mergeVector(std::vector<int> &arr, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	std::vector<int> L(n1);
	std::vector<int> R(n2);

	for (int i = 0; i < n1; ++i)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; ++j)
		R[j] = arr[m + 1 + j];

	int i = 0;
	int j = 0;
	int k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			++i;
		}
		else
		{
			arr[k] = R[j];
			++j;
		}
		++k;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		++i;
		++k;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		++j;
		++k;
	}
}

void PmergeMe::mergeSortVector(std::vector<int> &arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSortVector(arr, l, m);
		mergeSortVector(arr, m + 1, r);

		mergeVector(arr, l, m, r);
	}
}
