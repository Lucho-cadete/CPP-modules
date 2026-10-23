
#include "Array.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

template <typename T>
static void	printArray(std::string const &name, Array<T> const &array)
{
	std::cout << name << " (size " << array.size() << "): ";
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << "[" << array[i] << "] ";
	std::cout << std::endl;
}

/*
** Test from the subject's intranet page, with explicit messages.
** It fills an Array and a plain C array (mirror) with the same random
** values, copies the Array and destroys the copies, then checks that no
** value changed and that out-of-range accesses throw.
*/
static int	subjectTest(void)
{
	Array<int>	numbers(MAX_VAL);
	int			*mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int	value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << "Filled numbers and mirror with " << MAX_VAL
		<< " identical random values" << std::endl;

	{
		Array<int>	tmp = numbers;		// copy constructor
		Array<int>	test(tmp);			// copy constructor
	}									// tmp and test are destroyed here
	std::cout << "Copies tmp and test created and destroyed: no crash" << std::endl;

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cout << "KO: numbers[" << i << "] changed after the copies" << std::endl;
			delete [] mirror;
			return (1);
		}
	}
	std::cout << "OK: all " << MAX_VAL << " values unchanged after the copies" << std::endl;

	try
	{
		numbers[-2] = 0;
		std::cout << "KO: numbers[-2] did not throw" << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << "OK: numbers[-2] threw: " << e.what() << std::endl;
	}
	try
	{
		numbers[MAX_VAL] = 0;
		std::cout << "KO: numbers[" << MAX_VAL << "] did not throw" << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << "OK: numbers[" << MAX_VAL << "] threw: " << e.what() << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
		numbers[i] = rand();
	std::cout << "numbers is still usable after everything" << std::endl;

	delete [] mirror;
	return (0);
}

int	main(void)
{
	std::cout << "=== 1. Empty array ===" << std::endl;
	{
		Array<int>	empty;

		printArray("empty", empty);
		try
		{
			empty[0] = 42;
		}
		catch (std::exception &e)
		{
			std::cout << "empty[0]: exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== 2. Array of n elements, default-initialized ===" << std::endl;
	{
		Array<int>			numbers(5);
		Array<std::string>	words(3);

		printArray("numbers", numbers);
		printArray("words", words);
	}

	std::cout << "\n=== 3. Write and read with [] ===" << std::endl;
	{
		Array<int>	numbers(5);

		for (unsigned int i = 0; i < numbers.size(); i++)
			numbers[i] = i * 10;
		printArray("numbers", numbers);
	}

	std::cout << "\n=== 4. Copy constructor: deep copy ===" << std::endl;
	{
		Array<int>	original(3);

		original[0] = 1;
		original[1] = 2;
		original[2] = 3;

		Array<int>	copy(original);

		original[0] = 999;
		printArray("original", original);
		printArray("copy    ", copy);
	}

	std::cout << "\n=== 5. Assignment operator: deep copy ===" << std::endl;
	{
		Array<int>	original(3);
		Array<int>	other(10);

		original[0] = 1;
		original[1] = 2;
		original[2] = 3;
		other = original;
		original[0] = 999;
		printArray("original", original);
		printArray("other   ", other);
	}

	std::cout << "\n=== 6. Out of bounds ===" << std::endl;
	{
		Array<int>	numbers(5);

		try
		{
			numbers[5] = 42;
		}
		catch (std::exception &e)
		{
			std::cout << "numbers[5]: exception: " << e.what() << std::endl;
		}
		try
		{
			numbers[-1] = 42;
		}
		catch (std::exception &e)
		{
			std::cout << "numbers[-1]: exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== 7. Const array: read only ===" << std::endl;
	{
		Array<std::string>	words(2);

		words[0] = "hello";
		words[1] = "codam";

		Array<std::string> const	frozen(words);

		std::cout << "frozen[1]: " << frozen[1] << std::endl;
		// frozen[1] = "bye";   // does not compile: frozen is const
	}

	std::cout << "\n=== 8. Subject test (" << MAX_VAL << " random values) ===" << std::endl;
	return (subjectTest());
}
