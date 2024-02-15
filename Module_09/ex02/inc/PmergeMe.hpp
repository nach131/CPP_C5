/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:47:47 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/02/15 18:44:32 by nmota-bu         ###   ########.fr       */
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
#include "Colors_ft.hpp"

enum
{
	VEC,
	LST
};

class PmergeMe
{
private:
	// bool _startTimeInitialized; // Indica si el tiempo de inicio ha sido inicializado
	// clock_t _startTime;			// Tiempo de inic
	double _timeVec;
	double _timeLst;
	std::string _ori;
	std::vector<int> _vec;
	std::list<int> _lst;
	std::string _token;
	PmergeMe();
	double start(int);
	bool isValidToken(const std::string &token);
	void addToContainer(int);
	void print();
	void printList();

	void mergeList(std::list<int>::iterator l, std::list<int>::iterator m, std::list<int>::iterator r);
	void mergeSortList(std::list<int> &arr, std::list<int>::iterator l, std::list<int>::iterator r);
	void mergeVector(std::vector<int> &arr, int l, int m, int r);
	void mergeSortVector(std::vector<int> &arr, int l, int r);

public:
	PmergeMe(std::string);
	PmergeMe(const PmergeMe &);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &);
};

#endif
