
#include "Span.hpp"
#include <algorithm>

Span::Span(void) : _maxSize(0)
{}

Span::Span(unsigned int n) : _maxSize(n)
{}

Span::Span(Span const &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span(void)
{}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Span is full");
	_numbers.push_back(number);
}

long Span::longestSpan(void) const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("not enough numbers to find a span");

	int	smallest = *std::min_element(_numbers.begin(), _numbers.end());
	int	biggest = *std::max_element(_numbers.begin(), _numbers.end());

	return (static_cast<long>(biggest) - static_cast<long>(smallest));
}

long Span::shortestSpan(void) const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("not enough numbers to find a span");

	std::vector<int>	sorted(_numbers);

	std::sort(sorted.begin(), sorted.end());

	long	shortest = static_cast<long>(sorted[1]) - static_cast<long>(sorted[0]);

	for (size_t i = 2; i < sorted.size(); i++)
	{
		long	distance = static_cast<long>(sorted[i]) - static_cast<long>(sorted[i - 1]);

		if (distance < shortest)
			shortest = distance;
	}
	return (shortest);
}
