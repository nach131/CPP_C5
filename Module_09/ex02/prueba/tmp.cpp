PmergeMe::PmergeMe(const PmergeMe &other) : _ori(other._ori), _vec(other._vec), _lst(other._lst), _token(other._token) {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_ori = other._ori;
		_vec = other._vec;
		_lst = other._lst;
		_token = other._token;
	}
	return *this;
}

== == == ==

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

	class PmergeMe
{
private:
	std::string _ori;
	std::vector<int> _vec;
	std::list<int> _lst;
	std::string _token;

	static void mergeSort(std::vector<int> &arr, typename std::vector<int>::iterator l, typename std::vector<int>::iterator r)
	{
		if (std::distance(l, r) > 1)
		{
			typename std::vector<int>::iterator m = std::next(l, std::distance(l, r) / 2);

			mergeSort(arr, l, m);
			mergeSort(arr, m, r);

			std::inplace_merge(l, m, r);
		}
	}

	static void mergeSort(std::list<int> &arr, typename std::list<int>::iterator l, typename std::list<int>::iterator r)
	{
		if (std::distance(l, r) > 1)
		{
			typename std::list<int>::iterator m = std::next(l, std::distance(l, r) / 2);

			mergeSort(arr, l, m);
			mergeSort(arr, m, r);

			arr.merge(std::list<int>(m, r));
		}
	}

public:
	PmergeMe(std::string);
	PmergeMe(const PmergeMe &);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &);
};

PmergeMe::PmergeMe(std::string ori) : _ori(ori) {}

PmergeMe::PmergeMe(const PmergeMe &other) : _ori(other._ori), _vec(other._vec), _lst(other._lst), _token(other._token) {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_ori = other._ori;
		_vec = other._vec;
		_lst = other._lst;
		_token = other._token;
	}
	return *this;
}
