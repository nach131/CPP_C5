/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:47:47 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/02/15 11:56:35 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <limits.h>
#include <ctime>

enum
{
	VEC,
	LST
};

class PmergeMe
{
private:
	// bool _sorted;
	std::string _ori;
	std::vector<int> _vec;
	std::list<int> _lst;
	std::string _token;
	PmergeMe();
	void start(int);
	bool isValidToken(const std::string &token);
	void print(bool);
	double measureTimeMergeSort(int);
	void addToContainer(int);

public:
	PmergeMe(std::string);
	PmergeMe(const PmergeMe &);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &);
};

#endif
