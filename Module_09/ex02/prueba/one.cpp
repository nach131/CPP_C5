#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &arr)
{
	int n = arr.size();
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				// Swap
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	std::vector<int> vec = {5, 2, 9, 1, 6};

	std::cout << "Before sorting: ";
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	bubbleSort(vec);

	std::cout << "After sorting: ";
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
