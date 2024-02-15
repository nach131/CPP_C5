#include <iostream>
#include <vector>
#include <ctime>

void merge(std::vector<int> &arr, int l, int m, int r)
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

void mergeSort(std::vector<int> &arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void printVector(const std::vector<int> &arr)
{
	for (size_t i = 0; i < arr.size(); ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

double measureTimeMergeSort(std::vector<int> &arr)
{
	auto start = std::chrono::high_resolution_clock::now();
	mergeSort(arr, 0, arr.size() - 1);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = end - start;
	return duration.count();
}

int main()
{
	int arr[] = {5, 2, 9, 1, 6};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

	std::cout << "Before sorting: ";
	printVector(vec);

	double elapsedTime = measureTimeMergeSort(vec);

	std::cout << "After sorting: ";
	printVector(vec);

	std::cout << "Elapsed time for sorting: " << elapsedTime << " seconds." << std::endl;

	return 0;
}
