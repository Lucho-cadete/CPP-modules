
#pragma once

#include <vector>
#include <stdexcept>
#include <iterator>

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

		void addNumber(int number);
		long longestSpan(void) const;
		long shortestSpan(void) const;

		template <typename Iterator>
		void	addRange(Iterator first, Iterator last);
};

template <typename Iterator>
void Span::addRange(Iterator first, Iterator last)
{
	size_t	count = static_cast<size_t>(std::distance(first, last));

	if (count > _maxSize - _numbers.size())
		throw std::runtime_error("Span is full");
	_numbers.insert(_numbers.end(), first, last);
}
