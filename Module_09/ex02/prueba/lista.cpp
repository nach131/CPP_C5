#include <iostream>
#include <list>
#include <ctime>

void merge(std::list<int> &arr, std::list<int>::iterator l, std::list<int>::iterator m, std::list<int>::iterator r)
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

void mergeSort(std::list<int> &arr, std::list<int>::iterator l, std::list<int>::iterator r)
{
	if (std::distance(l, r) > 1)
	{
		std::list<int>::iterator m = l;
		std::advance(m, std::distance(l, r) / 2);

		mergeSort(arr, l, m);
		mergeSort(arr, m, r);

		merge(arr, l, m, r);
	}
}

void printList(const std::list<int> &arr)
{
	for (std::list<int>::const_iterator it = arr.begin(); it != arr.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

double measureTimeMergeSort(std::list<int> &arr)
{
	clock_t start = clock();
	mergeSort(arr, arr.begin(), arr.end());
	clock_t end = clock();
	double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000.0; // Convertir de segundos a milisegundos
	return duration;
}

int main()
{
	int arr[] = {5, 2, 9, 1, 6};
	std::list<int> list(arr, arr + sizeof(arr) / sizeof(arr[0]));

	std::cout << "Before sorting: ";
	printList(list);

	double elapsedTime = measureTimeMergeSort(list);

	std::cout << "After sorting: ";
	printList(list);

	std::cout << "Elapsed time for sorting: " << elapsedTime << " milliseconds." << std::endl;

	return 0;
}
