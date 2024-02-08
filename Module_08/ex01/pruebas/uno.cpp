#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
private:
	std::vector<int> numbers;
	unsigned int capacity;

public:
	Span(unsigned int N) : capacity(N) {}

	void addNumber(int num)
	{
		if (numbers.size() >= capacity)
		{
			throw std::out_of_range("Exceeded maximum capacity");
		}
		numbers.push_back(num);
	}

	int shortestSpan() const
	{
		if (numbers.size() <= 1)
		{
			throw std::logic_error("Not enough numbers to find span");
		}

		std::vector<int> sortedNumbers = numbers;
		std::sort(sortedNumbers.begin(), sortedNumbers.end());

		int minSpan = std::numeric_limits<int>::max();
		for (size_t i = 1; i < sortedNumbers.size(); ++i)
		{
			int span = sortedNumbers[i] - sortedNumbers[i - 1];
			minSpan = std::min(minSpan, span);
		}

		return minSpan;
	}

	int longestSpan() const
	{
		if (numbers.size() <= 1)
		{
			throw std::logic_error("Not enough numbers to find span");
		}

		return *std::max_element(numbers.begin(), numbers.end()) - *std::min_element(numbers.begin(), numbers.end());
	}
};

int main()
{
	{
		try
		{
			Span span(10000);

			for (int i = 1; i <= 10000; ++i)
			{
				span.addNumber(i);
			}

			std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << span.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	{
		try
		{
			Span span(10000);

			for (int i = 1; i <= 10000; ++i)
			{
				span.addNumber(rand() % (rand() % (300 + (i * 27))));
			}

			std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << span.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	{
		Span s(1);
		s.addNumber(42);
		try
		{
			std::cout << s.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			std::cout << s.shortestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			s.addNumber(24);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	// {
	// 	Span sp = Span(5);
	// 	sp.addNumber(6);
	// 	sp.addNumber(3);
	// 	sp.addNumber(17);
	// 	sp.addNumber(9);
	// 	sp.addNumber(11);
	// 	std::cout << sp.shortestSpan() << std::endl;
	// 	std::cout << sp.longestSpan() << std::endl;
	// }

	{
		try
		{
			Span span(10);
			// Span s2;
			int arr[] = {3, 71, 12, 45, 26, 80, 53, 33, 42, -12};

			for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
				span.addNumber(arr[i]);

			std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << span.longestSpan() << std::endl;
			// s2.addNumbers(myvector);
			// s.addNumber(42);
			// s.addNumber(420);
			// s.addNumber(402);
			// s.addNumber(4);
			// s.addNumber(2);
			// std::cout << s;
			// std::cout << s2;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		return 0;
	}
	return 0;
}
