#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::cout << "=== 1. Subject example ===" << std::endl;
	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== 2. addNumber on a full Span ===" << std::endl;
	{
		Span	sp(3);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		try
		{
			sp.addNumber(9);
		}
		catch (std::exception &e)
		{
			std::cout << "4th number: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== 3. Not enough numbers ===" << std::endl;
	{
		Span	sp(5);

		try
		{
			sp.longestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << "empty: " << e.what() << std::endl;
		}
		sp.addNumber(42);
		try
		{
			sp.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << "one number: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== 4. Repeated number ===" << std::endl;
	{
		Span	sp(3);

		sp.addNumber(5);
		sp.addNumber(20);
		sp.addNumber(5);
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== 5. INT_MIN and INT_MAX (no overflow) ===" << std::endl;
	{
		Span	sp(2);

		sp.addNumber(INT_MIN);
		sp.addNumber(INT_MAX);
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== 6. addRange from a vector and from a list ===" << std::endl;
	{
		std::vector<int>	numbers;

		numbers.push_back(6);
		numbers.push_back(3);
		numbers.push_back(17);

		std::list<int>	others;

		others.push_back(9);
		others.push_back(11);

		Span	sp(5);

		sp.addRange(numbers.begin(), numbers.end());
		sp.addRange(others.begin(), others.end());
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== 7. addRange that does not fit: nothing is added ===" << std::endl;
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

	std::cout << "\n=== 8. Copies are independent (deep copy) ===" << std::endl;
	{
		Span	original(5);

		original.addNumber(10);
		original.addNumber(20);

		Span	copy(original);
		Span	assigned(1);

		assigned = original;
		copy.addNumber(1000);
		assigned.addNumber(-1000);
		std::cout << "original longest: " << original.longestSpan() << std::endl;
		std::cout << "copy longest:     " << copy.longestSpan() << std::endl;
		std::cout << "assigned longest: " << assigned.longestSpan() << std::endl;
	}

	std::cout << "\n=== 9. 10 000 numbers with a known result ===" << std::endl;
	{
		std::vector<int>	numbers;

		for (int i = 0; i < 10000; i++)
			numbers.push_back(i * 2);

		Span	sp(10000);

		sp.addRange(numbers.begin(), numbers.end());
		std::cout << "shortest (expected 2):     " << sp.shortestSpan() << std::endl;
		std::cout << "longest (expected 19998):  " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== 10. 100 000 random numbers ===" << std::endl;
	{
		std::vector<int>	numbers;

		srand(static_cast<unsigned int>(time(NULL)));
		for (int i = 0; i < 100000; i++)
			numbers.push_back(rand());

		Span	sp(100000);

		sp.addRange(numbers.begin(), numbers.end());
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << std::endl;
	}
	return (0);
}
