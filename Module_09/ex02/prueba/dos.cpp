#include <vector>
#include <list>

template <typename T>
void merge(T &arr, typename T::iterator l, typename T::iterator m, typename T::iterator r)
{
	int n1 = std::distance(l, m) + 1;
	int n2 = std::distance(m, r) + 1;

	T L(l, m);
	T R(m, r);

	typename T::iterator itL = L.begin();
	typename T::iterator itR = R.begin();

	typename T::iterator it = l;
	while (itL != L.end() && itR != R.end())
	{
		if (*itL <= *itR)
		{
			*it = *itL;
			++itL;
		}
		else
		{
			*it = *itR;
			++itR;
		}
		++it;
	}

	while (itL != L.end())
	{
		*it = *itL;
		++itL;
		++it;
	}

	while (itR != R.end())
	{
		*it = *itR;
		++itR;
		++it;
	}
}

template <typename T>
void mergeSort(T &arr, typename T::iterator l, typename T::iterator r)
{
	if (std::distance(l, r) > 0)
	{
		typename T::iterator m = std::next(l, std::distance(l, r) / 2);

		mergeSort(arr, l, m);
		mergeSort(arr, m, r);

		merge(arr, l, m, r);
	}
}
