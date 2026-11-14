
#include "Span.hpp"
#include <iostream>

int	main(void)
{
	Span	sp(3);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	std::cout << "3 numbers added" << std::endl;
	try
	{
		sp.addNumber(9);
	}
	catch (std::exception &e)
	{
		std::cout << "4th number: " << e.what() << std::endl;
	}
	return (0);
}