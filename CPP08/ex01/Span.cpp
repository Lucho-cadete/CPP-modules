
#include "Span.hpp"

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

