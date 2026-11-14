
#pragma once

#include <vector>
#include <stdexcept>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span(void);

		void	addNumber(int number);
		long	longestSpan(void) const;
		long	shortestSpan(void) const;
};
