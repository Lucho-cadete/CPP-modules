
#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>

int	main(void)
{
	std::cout << "=== 1. std::vector: value found ===" << std::endl;
	{
		std::vector<int>	numbers;

		for (int i = 0; i < 5; i++)
			numbers.push_back(i * 10);
		std::vector<int>::iterator	it = easyfind(numbers, 20);
		std::cout << "found " << *it << " at position "
			<< std::distance(numbers.begin(), it) << std::endl;
	}

	std::cout << "\n=== 2. std::list: value found ===" << std::endl;
	{
		std::list<int>	numbers;

		for (int i = 0; i < 5; i++)
			numbers.push_back(i * 10);
		std::list<int>::iterator	it = easyfind(numbers, 40);
		std::cout << "found " << *it << " at position "
			<< std::distance(numbers.begin(), it) << std::endl;
	}

	std::cout << "\n=== 3. std::deque: value found ===" << std::endl;
	{
		std::deque<int>	numbers;

		for (int i = 0; i < 5; i++)
			numbers.push_back(i * 10);
		std::deque<int>::iterator	it = easyfind(numbers, 0);
		std::cout << "found " << *it << " at position "
			<< std::distance(numbers.begin(), it) << std::endl;
	}

	std::cout << "\n=== 4. Repeated value: returns the first one ===" << std::endl;
	{
		std::vector<int>	numbers;

		numbers.push_back(7);
		numbers.push_back(3);
		numbers.push_back(7);
		std::vector<int>::iterator	it = easyfind(numbers, 7);
		std::cout << "found " << *it << " at position "
			<< std::distance(numbers.begin(), it) << std::endl;
	}

	std::cout << "\n=== 5. The iterator points to the original element ===" << std::endl;
	{
		std::vector<int>	numbers;

		for (int i = 0; i < 5; i++)
			numbers.push_back(i * 10);
		*easyfind(numbers, 30) = 333;
		for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	std::cout << "\n=== 6. Value not found ===" << std::endl;
	{
		std::vector<int>	numbers;

		for (int i = 0; i < 5; i++)
			numbers.push_back(i * 10);
		try
		{
			easyfind(numbers, 99);
			std::cout << "this line is never printed" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "99: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== 7. Empty container ===" << std::endl;
	{
		std::list<int>	empty;

		try
		{
			easyfind(empty, 0);
		}
		catch (std::exception &e)
		{
			std::cout << "empty list: " << e.what() << std::endl;
		}
	}
	return (0);
}
