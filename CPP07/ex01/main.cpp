
#include "iter.hpp"

#include <iostream>
#include <string>
#include <cctype>

template <typename T>
void	print(T const &x)
{
	std::cout << "[" << x << "] ";
}

template <typename T>
void	increment(T &x)
{
	x++;
}

static void	toUpper(std::string &s)
{
	for (size_t i = 0; i < s.length(); i++)
		s[i] = static_cast<char>(std::toupper(s[i]));
}

int	main(void)
{
	int			numbers[5] = {1, 2, 3, 4, 5};
	std::string	words[3] = {"hello", "codam", "cpp"};
	int const	fixed[3] = {10, 20, 30};

	std::cout << "--- int, print ---" << std::endl;
	iter(numbers, 5, print<int>);
	std::cout << std::endl;

	std::cout << "--- int, increment, then print ---" << std::endl;
	iter(numbers, 5, increment<int>);
	iter(numbers, 5, print<int>);
	std::cout << std::endl;

	std::cout << "--- std::string, toUpper, then print ---" << std::endl;
	iter(words, 3, toUpper);
	iter(words, 3, print<std::string>);
	std::cout << std::endl;

	std::cout << "--- const int array, print ---" << std::endl;
	iter(fixed, 3, print<int>);
	std::cout << std::endl;

	// iter(fixed, 3, increment<int>);   // does not compile: elements are const

	return (0);
}
