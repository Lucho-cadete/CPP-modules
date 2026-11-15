#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>

int	main(void)
{
	std::cout << "=== addRange from a vector ===" << std::endl;
	{
		std::vector<int>	numbers;

		numbers.push_back(6);
		numbers.push_back(3);
		numbers.push_back(17);
		numbers.push_back(9);
		numbers.push_back(11);

		Span	sp(5);

		sp.addRange(numbers.begin(), numbers.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== addRange from a list, after addNumber ===" << std::endl;
	{
		std::list<int>	others;

		others.push_back(100);
		others.push_back(150);

		Span	sp(3);

		sp.addNumber(1);
		sp.addRange(others.begin(), others.end());
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== addRange that does not fit ===" << std::endl;
	{
		std::vector<int>	numbers;

		for (int i = 0; i < 10; i++)
			numbers.push_back(i);

		Span	sp(5);

		sp.addNumber(42);
		sp.addNumber(50);
		try
		{
			sp.addRange(numbers.begin(), numbers.end());
		}
		catch (std::exception &e)
		{
			std::cout << "10 numbers in a Span with 3 free places: " << e.what() << std::endl;
		}
		std::cout << "longest is still: " << sp.longestSpan() << std::endl;
	}
	return (0);
}
