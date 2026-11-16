#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator		iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

		MutantStack(void);
		MutantStack(MutantStack const &other);
		MutantStack	&operator=(MutantStack const &other);
		~MutantStack(void);

		iterator		begin(void);
		iterator		end(void);
		const_iterator	begin(void) const;
		const_iterator	end(void) const;
};

#include "MutantStack.tpp"
